#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <queue>

using namespace std;

class Node
{
public:
    Node *next;
    int value;
    string color;
    bool visited;

    Node() // constructor to initialize variables
    {
        next = NULL;
        color = "white";
    }
};

class LinkedList
{
public:
    Node *root;

    LinkedList()
    {
        root = NULL;
    }

    void insertNode(int value) // creating linked list
    {
        Node *newNode = new Node; //creating new Node to append to end of linked list
        newNode->value = value;
        newNode->next = NULL;

        Node *nodePtr = new Node; // creating a ptr to follow linked list and provides ease of use to add next Node
        nodePtr = root;

        if (root == NULL) // if there is no Node at begining make newNode root.
        {
            root = newNode;
            newNode->next = NULL;
        }

        if (root != NULL)
        {

            while (nodePtr->next != NULL) // continue through linked list until you reach end and then append newNode to it
            {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = newNode;
        }
    }

    int iterator(int too)
    {
        Node *nodePtr = root;
        for (int i = 0; i < too; i++)
        {
            if (root != NULL)
            {
                nodePtr = nodePtr->next;
            }
            else
            {
                cout << "Reached end of list!";
            }
            return nodePtr->value;
        }
    }

    int size()
    {
        Node *nodePtr = root;
        int size;
        while (nodePtr != NULL)
        {
            size++;
            nodePtr = nodePtr->next;
        }
        return size;
    }

    void PrintList()
    {
        Node *nodePtr = root;
        while (nodePtr != NULL)
        {
            cout << nodePtr->value << " - ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }
};

class edge
{
public:
    int origin;
    LinkedList list;
    bool visited;

    edge()
    {
        visited = true;
    }
};

class graph_
{
private:
    vector<edge> vectorOfEdges; // using class edge as type for vector. This is what makes OOP so beautiful.
    int vertices;               // private variables are used in the class but are not seen in main unless we use getters and setters ~note to self ~learned thoroughly in csci 117
    int counter;
    int v;

public:
    graph_()
    {
        vertices = v;
        vectorOfEdges.clear();
    }

    /*  The following code makes a graph in which each vector element holds a linked list value.
                As seen in the slides:
                a -> b -> c
                b -> c
                c -> d -> e
                d -> f -> g -> h
                */
    void addEdges(int val)
    {

        for (int i = 0; i < vectorOfEdges.size(); i++)
        {
            edge edgey; // why cant this be accessed?
            edgey = vectorOfEdges[i];
            if (counter == 0)
            { // means element is not found
                edgey.list.insertNode(val);
                vectorOfEdges[i] = edgey;
                counter++;
            }

            if (counter == 1)
            {
                vectorOfEdges[i].list.insertNode(val);
            }
        }
    }

    void print()
    {
        edge e;
        for (int i = 0; i < vectorOfEdges.size(); i++)
        {
            e = vectorOfEdges[i]; // creating an instance of vector with linked list values appended to origin
            e.list.PrintList();
            cout << endl;
        }
    }

    void BFS(int start)
    {
        edge e;
        queue<int> g;
        Node *ptr = e.list.root;

        while (!g.empty())
        {
            int x = g.front();
            g.pop();

            for (int i = start; i < vectorOfEdges.size(); i++)
            {
                e = vectorOfEdges[i];
                if (vectorOfEdges[i].visited = false)
                { // having issues getting this connected to a linked list.(change of name)

                    while (ptr != NULL)
                    {
                        if (ptr->color == "white") // visiting each value of the linked list
                        {
                            g.push(ptr->value);
                            ptr->color = "black";
                            ptr = ptr->next;
                        }

                        else
                        {
                            ptr = ptr->next; // traversing to next element as long origin -> linked list is not NULL eg. 0 -> 1 -> 2 2 marks end of origin linked list value
                        }
                    }
                }
                vectorOfEdges[i].visited = true;
            }
        }
    }
};

class DFS
{

    // list <int>* l; //prefered method

public:
    void addEdge(int i, int value)
    { // trying to incorporate linked list instead of using list
        LinkedList list;
        list.insertNode(value); // this only works if the list is already created. I haven't implemented a fail safe. It is better to use list so that I can initialize.
    }

    void DFS_visit(int value, vector<string> visit)
    {
        visit.at(value) = "black"; //marking current as visited;
        LinkedList list;

        for (int i = list.iterator(0); i < list.iterator(list.size()); i++)
        { // my own take on lists. HOWEVER list is a double linked list
            if (visit.at(i) == "white")
            {
                DFS_visit(i, visit);
            }
        }
    }

    void DFS_Build(int value)
    {
        vector<string> visit;
        for (int i = 0; i < visit.size(); i++)
        {
            visit.at(i) = "white";
        }
        DFS_visit(value, visit);
    }
};

int main()
{
                graph_ g;
                g.addEdges(5);
                g.addEdges(2);
                g.addEdges(5);
                g.addEdges(7);
                g.addEdges(6);
                g.addEdges(3);
                g.print();
}