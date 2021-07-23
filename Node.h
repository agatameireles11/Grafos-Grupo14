/**************************************************************************************************
 * Implementation of the TAD Node
**************************************************************************************************/

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <fstream>
#include "Edge.h" // Include of the Edge class

using namespace std;

// Definition of the Node class
class Node{

    // Attributes
private:
    Edge* first_edge;
    Edge* last_edge;
    int id;
    unsigned int in_degree;
    unsigned int out_degree;
    float weight;
    Node* next_node;

public:
    // Constructor
    Node(int id);
    // Destructor
    ~Node();
    // Getters
    Edge* getFirstEdge();
    Edge* getLastEdge();
    int getId();
    int getInDegree();
    int getOutDegree();
    float getWeight();
    Node* getNextNode();
    // Setters
    void setNextNode(Node* node);
    void setWeight(float weight);
    // Other methods
    bool searchEdge(int target_id);
    void insertEdge(Node* target_node, bool directed,  float weight);
    void removeAllEdges();
    int removeEdge(Node* target_node, bool directed);
    void incrementOutDegree();
    void decrementOutDegree();
    void incrementInDegree();
    void decrementInDegree();
    Edge* hasEdgeBetween(int target_id);

    // Auxiliar methods
    void saveEdges(ofstream& output_file, bool weighted_edge, bool directed);

};

#endif // NODE_H_INCLUDED