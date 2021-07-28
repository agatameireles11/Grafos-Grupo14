#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <utility>
#include <tuple>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include "Graph.h"
#include "Node.h"

using namespace std;

Graph* leitura(ifstream& input_file, int directed, int weightedEdge, int weightedNode){

    //Variaveis para auxiliar na criacao dos nao no Grafo
    int idNodeSource;
    int idNodeTarget;
    int order;

    //Pegando a ordem do grafo
    input_file >> order;

    //Criando objeto grafo
    Graph* graph = new Graph(order, directed, weightedEdge, weightedNode);

    //Leitura de arquivo

    if(!graph->getWeightedEdge() && !graph->getWeightedNode()){

        while(input_file >> idNodeSource >> idNodeTarget) {

            graph->insertEdge(idNodeSource, idNodeTarget, 0);

        }

    }else if(graph->getWeightedEdge() && !graph->getWeightedNode() ){

        float edgeWeight;

        while(input_file >> idNodeSource >> idNodeTarget >> edgeWeight) {

            graph->insertEdge(idNodeSource, idNodeTarget, edgeWeight);

        }

    }else if(graph->getWeightedNode() && !graph->getWeightedEdge()){

        float nodeSourceWeight, nodeTargetWeight;

        while(input_file >> idNodeSource >> nodeSourceWeight >> idNodeTarget >> nodeTargetWeight) {

            graph->insertEdge(idNodeSource, idNodeTarget, 0);
            graph->getNode(idNodeSource)->setWeight(nodeSourceWeight);
            graph->getNode(idNodeTarget)->setWeight(nodeTargetWeight);

        }

    }else if(graph->getWeightedNode() && graph->getWeightedEdge()){

        float nodeSourceWeight, nodeTargetWeight, edgeWeight;

        while(input_file >> idNodeSource >> nodeSourceWeight >> idNodeTarget >> nodeTargetWeight >> edgeWeight) {

            graph->insertEdge(idNodeSource, idNodeTarget, edgeWeight);
            graph->getNode(idNodeSource)->setWeight(nodeSourceWeight);
            graph->getNode(idNodeTarget)->setWeight(nodeTargetWeight);

        }

    }

    return graph;
}

/*Graph* leituraInstancia(ifstream& input_file, int directed, int weightedEdge, int weightedNode){

    //VariÃ¡veis para auxiliar na criaÃ§Ã£o dos nÃ³s no Grafo
    int idNodeSource;
    int idNodeTarget;
    int order;
    int numEdges;

    //Pegando a ordem do grafo
    //input_file >> order >> numEdges;
    input_file >> order;

    //Criando objeto grafo
    Graph* graph = new Graph(order, directed, weightedEdge, weightedNode);

    //Leitura de arquivo
    while(input_file >> idNodeSource >> idNodeTarget) {

        graph->insertEdge(idNodeSource, idNodeTarget, 0);
    }

    return graph;
}*/

int menu(){

    int selecao;

    cout << "MENU" << endl;
    cout << "----" << endl;
    cout << "[1] Subgrafo induzido por conjunto de vÃ©rtices" << endl;
    cout << "[2] Caminho MÃ­nimo entre dois vÃ©rtices - Dijkstra" << endl;
    cout << "[3] Caminho MÃ­nimo entre dois vÃ©rtices - Floyd" << endl;
    cout << "[4] Ãrvore Geradora MÃ­nima de Prim" << endl;
    cout << "[5] Ãrvore Geradora MÃ­nima de Kruskal" << endl;
    cout << "[6] Imprimir caminhamento em largura" << endl;
    cout << "[7] Imprimir ordenacao topolÃ³gica" << endl;
    cout << "[8] Algoritmo Guloso" << endl;
    cout << "[9] Algoritmo Guloso Randomizado " << endl;
    cout << "[10] Algoritmo Guloso Randomizado Reativo" << endl;
    cout << "[0] Sair" << endl;

    cin >> selecao;

    return selecao;

}

void selecionar(int selecao, Graph* graph, ofstream& output_file){

    switch (selecao) {
        case 0: {
            graph->agmKruskal(output_file);
            exit(1);
            break;
        }
        //Subgrafo induzido por um conjunto de vÃ©rtices X;
        case 1:{
            break;
        }
            //Caminho mÃ­nimo entre dois vÃ©rtices usando Dijkstra;
        case 2:{
            //float aux = graph->dijkstra(1, 4);
            break;
        }

            //Caminho mÃ­nimo entre dois vÃ©rtices usando Floyd;
        case 3:{

            break;
        }

            //AGM - Kruscal;
        case 4:{



            break;
        }

            //AGM Prim;
        case 5:{

            break;
        }

            //Busca em largura;
        case 6:{

            break;
        }
            //OrdenaÃ§Ã£o Topologica;
        case 7:{


            break;
        }
        case 8: {

        }
        default:
        {

            cout << " Error!!! invalid option!!" << endl;
        }

    }
}

int mainMenu(ofstream& output_file, Graph* graph){

    int selecao = 1;

    while(selecao != 0){
        system("cls");
        selecao = menu();

        if(output_file.is_open())
            selecionar(selecao, graph, output_file);

        else
            cout << "Unable to open the output_file" << endl;

        output_file << endl;

    }

    return 0;
}



int main(int argc, char const *argv[]) {

    //VerificaÃ§Ã£o se todos os parÃ¢metros do programa foram entrados
    if (argc != 6) {

        cout << "ERROR: Expecting: ./<program_name> <input_file> <output_file> <directed> <weighted_edge> <weighted_node> " << endl;
        return 1;

    }

    string program_name(argv[0]);
    string input_file_name(argv[1]);

    string instance;
    if(input_file_name.find("v") <= input_file_name.size()){
        string instance = input_file_name.substr(input_file_name.find("v"));
        cout << "Running " << program_name << " with instance " << instance << " ... " << endl;
    }

    //Abrindo arquivo de entrada
    ifstream input_file;
    ofstream output_file;
    input_file.open(argv[1], ios::in);
    output_file.open(argv[2], ios::out | ios::trunc);



    Graph* graph;
    if(input_file.is_open()){

        graph = leitura(input_file, atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));

    }else
        cout << "Unable to open " << argv[1];




    mainMenu(output_file, graph);



    //Fechando arquivo de entrada
    input_file.close();

    //Fechando arquivo de saÃ­da
    output_file.close();


    // Node *node1 = new Node(0);
    // Node *node2 = new Node(1);
    // Node *node3 = new Node(2);

    // node1->insertEdge(node2, 0, 0);
    // node1->insertEdge(node3, 0, 0);
    // node2->insertEdge(node3, 0, 0);

    // node2->removeAllEdges();

    // cout << node1->getOutDegree() << " " << node2->getOutDegree() << " " << node3->getOutDegree() << "\n";
    // cout << node1->getInDegree() << " " << node2->getInDegree() << " " << node3->getInDegree();

    /*
    Graph* graph = new Graph( 0, 1, 0, 0);
    graph->insertNode( 0);
    graph->insertNode( 1);
    graph->insertNode( 2);

    graph->insertEdge(1,0,0);

    cout << graph->getNode(0)->searchEdge(1) << endl << "Grau: " << graph->getNode(1)->getOutDegree() << endl;
    graph->print();*/


    return 0;
}
