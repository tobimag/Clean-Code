#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

#include <iterator>

/*
 * 1 1 1 1 0 1 0 1 0 1 1 1
 *
 * 1 1 1 1
 * 0 1 0 1
 * 0 1 1 1
 *
 *
 * 0,0 => 0  1,0 => 1  2,0 => 2  3,0 => 3
 * 0,1 => 4  1,1 => 5  2,1 => 6  3,1 => 7
 * 0,2 => 8  1,2 => 9  2,2 => 10 3,2 => 11
 *
 * 0  1  2  3
 * 4  5  6  7
 * 8  9  10 11
 *
 */


int xy2MapIndex(const int nX, const int nY, const int nMapWidth)
{
   return nMapWidth * nY + nX;
}

std::pair<int, int> MapIndexToXY(const int mapIndex, const int nMapWidth)
{
   return std::make_pair(mapIndex / nMapWidth, mapIndex % nMapWidth);
}

int HeuristicCostEstimate(const int startIndex, const int goalIndex, const int nMapWidth)
{
   const auto startPoint = MapIndexToXY(startIndex, nMapWidth);
   const auto endPoint = MapIndexToXY(goalIndex, nMapWidth);

   return abs(endPoint.first - startPoint.first) + abs(endPoint.second - startPoint.second);
}

std::vector<int> getNeighbours(const int index, const unsigned char* pMap, const int nMapWidth, const int nMapHeight)
{
   std::vector<int> neighbours;
   
   const int aboveNeighbour = index - nMapWidth;
   // operator && evaluate left operand first and if the value is false it avoids evaluating right operand
   if (aboveNeighbour > 0 && pMap[aboveNeighbour])
   {
      neighbours.push_back(aboveNeighbour);
   }

   const int rightNeighbour = index + 1;
   if (rightNeighbour % nMapWidth != 0 && pMap[rightNeighbour])
   {
      neighbours.push_back(rightNeighbour);
   }

   const int belowNeighbour = index + nMapWidth;
   if (belowNeighbour < nMapWidth * nMapHeight && pMap[belowNeighbour])
   {
      neighbours.push_back(belowNeighbour);
   }

   const int leftNeighbour = index - 1;
   if ((leftNeighbour + 1) % nMapWidth != 0 && pMap[leftNeighbour])
   {
      neighbours.push_back(leftNeighbour);
   }

   return neighbours;
}

int reconstructPath(const std::map<int, int> &cameFrom, int current)
{
   auto it = cameFrom.find(current);
   while(it != cameFrom.end())
   {
      std::cout << it->first << "-";
      it = cameFrom.find(it->second);
   }

   return 0;
}

int FindPath(const int nStartX, const int nStartY,
             const int nTargetX, const int nTargetY, 
             const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
             int* pOutBuffer, const int nOutBufferSize) 
{
   const int startIndex = xy2MapIndex(nStartX, nStartY, nMapWidth);
   const int goalIndex = xy2MapIndex(nTargetX, nTargetY, nMapWidth);

   std::vector<int> mapIndicies(nMapWidth * nMapHeight);
   std::iota(std::begin(mapIndicies), std::end(mapIndicies), 0);

   std::vector<int> closedSet;
   std::vector<int> openSet = {startIndex};
   
   std::map<int, int> cameFrom;
   
   std::map<int, int> gScore;
   for (auto index : mapIndicies)
   {
      gScore.emplace(index, std::numeric_limits<int>::max());
   }
   gScore[startIndex] = 0;

   std::map<int, int> fScore;
   for (auto index : mapIndicies)
   {
      fScore.emplace(index, std::numeric_limits<int>::max());
   }
   fScore[startIndex] = HeuristicCostEstimate(startIndex, goalIndex, nMapWidth);

   while (!openSet.empty())
   {
      std::vector<std::pair<int, int>> openSetFScore;
      std::copy_if(std::begin(fScore), std::end(fScore), std::back_inserter(openSetFScore),
            [&openSet](auto i){return std::find(std::begin(openSet), std::end(openSet), i.first) != std::end(openSet);});
     
      
      std::cout << "Chosing from nodes...\n";
      for (auto node : openSetFScore)
      {
         std::cout << "F-score of Node " << node.first << ": " << node.second << "\n";
      }

      auto current = min_element(std::begin(openSetFScore), std::end(openSetFScore), [](auto i, auto j){return i.second < j.second;})->first;
      std::cout << "Current node is " << current << "\n";      

      if (current == goalIndex)
      {
         std::cout << "Current node is the target!\n";
         return reconstructPath(cameFrom, current);
      }

      openSet.erase(std::find(std::begin(openSet), std::end(openSet), current));
      closedSet.push_back(current);

      auto neighbours = getNeighbours(current, pMap, nMapWidth, nMapHeight);
      
      for(auto neighbour : neighbours)
      {
         std::cout << " Investigating neighbour " << neighbour << "\n";
         if (std::find(std::begin(closedSet), std::end(closedSet), neighbour) != std::end(closedSet))
         {
            std::cout << " Node " << neighbour << " has already been investigated.\n";
            continue;
         }

         if (std::find(std::begin(openSet), std::end(openSet), neighbour) == std::end(openSet))
         {
            std::cout << " Node " << neighbour << " added to open set\n";
            openSet.push_back(neighbour);
         }
         
         const auto tentativeScore = gScore[current] + 1;
         if(tentativeScore > gScore[neighbour])
         {
            std::cout << " This is not a better path...\n";
            continue;
         }
         
         std::cout << " This path might be something!\n";
         cameFrom.emplace(neighbour, current);
         gScore[neighbour] = tentativeScore;
         fScore[neighbour] = gScore[neighbour] + HeuristicCostEstimate(neighbour, goalIndex, nMapWidth);

         std::cout << " G-Score of node " << neighbour << " is " << gScore[neighbour] << "\n";
         std::cout << " F-Score of node " << neighbour << " is " << fScore[neighbour] << "\n";

         for (auto aGScore : gScore)
         {
            std::cout << " G-Score node " << aGScore.first << ": " << aGScore.second << "\n";
         }

         for (auto anFScore : fScore)
         {
         
            std::cout << " F-Score node " << anFScore.first << ": " << anFScore.second << "\n";
         }
      }
      std::cout << "No more neigbours to investigate\n";
   }

   return -1;
}

int main()
{
   unsigned char pMap[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1};
   int pOutBuffer[12];
   std::cout << FindPath(0, 0, 1, 2, pMap, 4, 3, pOutBuffer, 12) << std::endl;
}
