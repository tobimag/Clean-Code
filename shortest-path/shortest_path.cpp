#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

class Node
{
   public:
      Node(int x, int y)
         : x(x),
           y(y),
           distanceFromStart(std::numeric_limits<int>::max()),
           priority(std::numeric_limits<int>::max()),
           previousNodeXY(std::make_pair<int, int>(-1,-1))
      {}

      Node& operator=(const Node& rhs) = default;

   int getPriority() const
   {
      return priority;
   }

   int getDistanceFromStart() const
   {
      return distanceFromStart;
   }

   int getX() const
   {
      return x;
   }

   int getY() const
   {
      return y;
   }

   const std::pair<int, int> getPreviousNodeXY() const
   {
      return previousNodeXY;
   }

   void updateDistanceFromStart(const int newDistanceFromStart)
   {
      distanceFromStart = newDistanceFromStart;
   }

   void updatePriority(const int newPriority)
   {
      priority = newPriority;
   }

   void setPreviousNodeXY(const Node& node)
   {
      previousNodeXY = std::make_pair<int, int>(node.getX(), node.getY());
   }

   private:

      int x;
      int y;
      int distanceFromStart;
      int priority;
      std::pair<int, int> previousNodeXY;
};


bool operator<(const Node &lhs, const Node &rhs)
{
   return lhs.getPriority() > rhs.getPriority();
}

bool operator==(const Node &lhs, const Node &rhs)
{
   return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

bool operator==(const Node &lhs, const std::pair<int, int> rhs)
{
   return lhs.getX() == rhs.first && lhs.getY() == rhs.second;
}

std::ostream& operator<<(std::ostream& os, const Node& node)
{
   os << "(" << node.getX() << "," << node.getY() << ")";
   return os;
}

class Map
{
   public:
      Map(int aWidth, int aHeight, const unsigned char* aMap)
         : width(aWidth), height(aHeight), theMap(aMap)
         {}
      
      int heuristicCostEstimate(const Node& node, const Node& target)
      {
         return abs(node.getX() - target.getX()) + abs(node.getY() - target.getY());
      }

      int reconstructPath(const Node& node, const std::vector<Node>& visitedNodes, int* pOutBuffer, const int nOutBufferSize)
      {
         std::vector<int> path;
         path.reserve(width*height);
         path.push_back(xy2MapIndex(node.getX(), node.getY()));
         auto current = std::find(visitedNodes.begin(), visitedNodes.end(), node.getPreviousNodeXY());
         while(current != visitedNodes.end())
         {
            path.push_back(xy2MapIndex(current->getX(), current->getY()));
            current = std::find(visitedNodes.begin(), visitedNodes.end(), current->getPreviousNodeXY());
         }
         path.pop_back();
         
         if(path.size() > nOutBufferSize)
         {   
            return -1;
         }

         std::reverse_copy(path.begin(), path.end(), pOutBuffer);
         return path.size();
      }

      std::vector<Node> getNeighbours(const Node& node)
      {
         
         std::vector<Node> neighbours;

         Node neighbourAbove = Node(node.getX(), node.getY() - 1);
         if (nodeIsValid(neighbourAbove))
         {
            neighbours.push_back(neighbourAbove);
         }

         Node rightNeighbour = Node(node.getX() + 1, node.getY()); 
         if (nodeIsValid(rightNeighbour))
         {
            neighbours.push_back(rightNeighbour);
         }

         Node neighbourBelow = Node(node.getX(), node.getY() + 1);
         if (nodeIsValid(neighbourBelow))
         {
            neighbours.push_back(neighbourBelow);
         }

         Node leftNeighbour = Node(node.getX() - 1, node.getY());
         if (nodeIsValid(leftNeighbour))
         {
            neighbours.push_back(leftNeighbour);
         }

         return neighbours;
      }

   private:

      bool nodeIsValid(const Node& node)
      {
         const int x = node.getX();
         const int y = node.getY();
      
         return x >= 0 && x < width && y >= 0 && y < height && theMap[xy2MapIndex(x, y)];
      }

      int xy2MapIndex(const int x, const int y)
      {
         return width * y + x;
      }

      int width;
      int height;
      const unsigned char* theMap;
};



int FindPath(const int nStartX, const int nStartY,
             const int nTargetX, const int nTargetY, 
             const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
             int* pOutBuffer, const int nOutBufferSize) 
{
   Map theMap = Map(nMapWidth, nMapHeight, pMap);
   
   Node start(nStartX, nStartY);
   Node target(nTargetX, nTargetY);

   std::priority_queue<Node> nodesToVisit;
   nodesToVisit.push(start);
  
   std::vector<Node> visitedNodes;
   visitedNodes.reserve(nMapWidth*nMapHeight);

   while(!nodesToVisit.empty())
   {
      Node current = nodesToVisit.top();

      if (current == target)
      {
         return theMap.reconstructPath(current, visitedNodes, pOutBuffer, nOutBufferSize);
      }

      nodesToVisit.pop();
      visitedNodes.push_back(current);
      
      auto neighbours = theMap.getNeighbours(current);
      for(auto neighbour : neighbours)
      {
         // Have we already visited this node?
         if(std::find(visitedNodes.begin(), visitedNodes.end(), neighbour) != visitedNodes.end())
         {
            continue;
         }
      
         const auto newDistance = current.getDistanceFromStart() + 1; // Cost between all nodes is 1
         // Have we found a better way to get to this node?
         if (newDistance > neighbour.getDistanceFromStart())
         {
            continue;
         }

         neighbour.updateDistanceFromStart(newDistance);
         neighbour.updatePriority(newDistance + theMap.heuristicCostEstimate(neighbour, target));
         neighbour.setPreviousNodeXY(current);
         
         nodesToVisit.push(neighbour);

      }

   }


   return -1;
}

int main()
{
   unsigned char pMap[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1};
   int pOutBuffer[12];
   int res = FindPath(0, 0, 1, 2, pMap, 4, 3, pOutBuffer, 12);

   std::cout << res << "\n";
   for(int i = 0; i < res; ++i)
   {
      std::cout << pOutBuffer[i] << " ";
   }
   std::cout << "\n\n";
    
   unsigned char pMap2[] = {0, 0, 1, 0, 1, 1, 1, 0, 1};
   int pOutBuffer2[7];
   int res2 = FindPath(2, 0, 0, 2, pMap2, 3, 3, pOutBuffer2, 7);
      
   std::cout << res2 << "\n";
   for(int i = 0; i < res2; ++i)
   {
      std::cout << pOutBuffer2[i] << " ";
   }
   std::cout << "\n"; 
}

