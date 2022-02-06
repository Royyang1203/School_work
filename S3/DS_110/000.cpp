
// // CPP program to implement traveling salesman
// // problem using naive approach.
// #include <bits/stdc++.h>
// using namespace std;
// #define V 6

// // implementation of traveling Salesman Problem
// int travllingSalesmanProblem(int graph[][V], int s)
// {
//     // store all vertex apart from source vertex
//     vector<int> vertex;
//     for (int i = 0; i < V; i++)
//         if (i != s)
//             vertex.push_back(i);

//     // store minimum weight Hamiltonian Cycle.
//     int min_path = INT_MAX;
//     do
//     {
//         // store current Path weight(cost)
//         int current_pathweight = 0;

//         // compute current path weight
//         int k = s;
//         for (int i = 0; i < vertex.size(); i++)
//         {
//             current_pathweight += graph[k][vertex[i]];
//             k = vertex[i];
//         }
//         current_pathweight += graph[k][s];

//         // update minimum
//         min_path = min(min_path, current_pathweight);

//     } while (
//         next_permutation(vertex.begin(), vertex.end()));

//     return min_path;
// }

// // Driver Code
// int main()
// {
//     // matrix representation of graph
//     int graph[][V] = {{0, 10000, 245, 115, 145, 175},
//                       {1000, 0, 450, 645, 10000, 10000},
//                       {245, 450, 0, 220, 385, 20000},
//                       {115, 645, 220, 0, 260, 125},
//                       {145, 10000, 385, 260, 0, 320},
//                       {175, 2000, 2000, 125, 320, 0}};
//     int s = 0;
//     cout << travllingSalesmanProblem(graph, s) << endl;
//     return 0;
// }

#include <iostream>
#include <queue>

using namespace std;
int main()
{
    queue<pair<int, double>> q;
    q.push(pair<int, double>(3, 5.3));
    pair<int, double> ee = q.tail();
    cout << ee.first << " " << ee.second;
}