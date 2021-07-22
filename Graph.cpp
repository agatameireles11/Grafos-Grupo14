#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <float.h>
#include <iomanip>

using namespace std;

/**************************************************************************************************
 * Defining the Graph's methods
**************************************************************************************************/

// Constructor
Graph::Graph(int order, bool directed, bool weighted_edge, bool weighted_node)
{

    this->order = order;
    this->directed = directed;
    this->weighted_edge = weighted_edge;
    this->weighted_node = weighted_node;
    this->first_node = this->last_node = nullptr;
    this->number_edges = 0;
}

// Destructor
Graph::~Graph()
{

    Node *next_node = this->first_node;

    while (next_node != nullptr)
    {

        next_node->removeAllEdges();
        Node *aux_node = next_node->getNextNode();
        delete next_node;
        next_node = aux_node;
    }
}

// Getters
int Graph::getOrder()
{

    return this->order;
}
int Graph::getNumberEdges()
{

    return this->number_edges;
}
//Function that verifies if the graph is directed
bool Graph::getDirected()
{

    return this->directed;
}
//Function that verifies if the graph is weighted at the edges
bool Graph::getWeightedEdge()
{

    return this->weighted_edge;
}

//Function that verifies if the graph is weighted at the nodes
bool Graph::getWeightedNode()
{

    return this->weighted_node;
}


Node *Graph::getFirstNode()
{

    return this->first_node;
}

Node *Graph::getLastNode()
{

    return this->last_node;
}

// Other methods
/*
    The outdegree attribute of nodes is used as a counter for the number of edges in the graph.
    This allows the correct updating of the numbers of edges in the graph being directed or not.
*/
void Graph::insertNode(int id)
{
    if (!this->searchNode(id))
    {
        Node* new_node = new Node(id);

        if(this->first_node != nullptr)
        {
            this->last_node->setNextNode(new_node);
            this->last_node = new_node;
        }
        else
        {
            this->first_node = new_node;
            this->last_node = this->first_node;
        }
    }
    else
    {
        cout << "ERROR: O no ja existe" << endl;
    }
}

void Graph::insertEdge(int id, int target_id, float weight)
{

}

void Graph::removeNode(int id){
    if(searchNode(id)) {
        Node* node = this->getFirstNode();
        Node* temp;
        if(node->getId() == id) {
            delete node;
        }
        else {
            while(node != nullptr) {
                if(node->getId() == id) {
                    temp->setNextNode(node->getNextNode());
                    break;
                }
                temp = node;
                node = node->getNextNode();
            }
            if(node == this->getLastNode()) {
                this->last_node = temp;
            }
            Node* aux = this->getFirstNode();
            while(aux != nullptr) {
                aux->removeEdge(node, this->directed);
                aux = aux->getNextNode();
            }
        }
        delete node;
    }
    else {
        cout << "Nó não encontrado!";
    }
}

bool Graph::searchNode(int id)
{
    if(this->first_node != nullptr)
    {
        for(Node* aux = this->first_node; aux != nullptr; aux = aux->getNextNode())
        {
            if(aux->getId() == id)
            {
                return true;
            }
        }
    }
    return false;
}

Node *Graph::getNode(int id)
{
    if(this->first_node != nullptr)
    {
        for(Node* aux = this->first_node; aux != nullptr; aux = aux->getNextNode())
        {
            if(aux->getId() == id)
            {
                return aux;
            }
        }
        cout << "ERROR: No nao encontrado no grafo!" << endl;
        return NULL;
    }
    cout << "ERROR: O grafo esta vazio!" << endl;
    return NULL;
}

void Graph::print()
{
    if(this->first_node != nullptr)
    {
        for(Node* aux = this->first_node; aux != nullptr; aux = aux->getNextNode())
        {
            cout << "No: "  << aux->getId() << endl;
        }
    }
}


//Function that prints a set of edges belongs breadth tree

void Graph::breadthFirstSearch(ofstream &output_file){

}



float Graph::floydMarshall(int idSource, int idTarget){

}



float Graph::dijkstra(int idSource, int idTarget){

}

//function that prints a topological sorting
void topologicalSorting(){

}

void breadthFirstSearch(ofstream& output_file){

}
Graph* getVertexInduced(int* listIdNodes){

}

Graph* agmKuskal(){

}

Graph* agmPrim(){

}

void Graph::directedTransitiveClosure(int id) {
    /*
    int foo[10000];
    Node* node = this->getNode(id);
    foo[0] = id;
    int i = 1;
    while(node->getFirstEdge() != nullptr) {
        Edge* edge = node->getFirstEdge();
        int id = edge->getTargetId();
        Node* targetNode = this->getNode(id);
        node->removeEdge(id, 0, targetNode);
        i++;
        foo[i] = id;
    }
    for(int j = 0; j < sizeof(foo); j++) {
        cout << foo[j];
    } */
}