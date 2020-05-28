#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class Node
{
public:
    string key;
    T value;
    Node<T> *next;

    Node(string key, T val) //constructor
    {
        this->key = key;
        value = val;
        next = NULL;
    }
    ~Node() //distructor
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class Hashtable
{
    Node<T> **table; //pointer to an array of pointers
    int current_size;
    int table_size;

    int hashFn(string key)
    {
        int id = 0;
        int p = 1;
        for (int j = 0; j < key.length(); j++)
        {
            id = id + (key[j] * p) % table_size;
            id = id % table_size;
            p = (p * 27) % table_size;
        }
        return id;
    }

    void rehash()
    {
        Node<T> **old_table = table;
        int old_table_size = table_size;
        table_size = 2 * table_size;
        table = new Node<T> *[table_size];

        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
        current_size = 0;

        //shift elements from old to new
        for (int i = 0; i < old_table_size; i++)
        {
            Node<T> *temp = old_table[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            if (old_table[i] != NULL)
            {
                delete old_table[i];
            }
        }

        delete[] old_table;
    }

public:
    Hashtable(int ts = 7)
    {
        table_size = ts;
        table = new Node<T> *[table_size];
        current_size = 0;
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T value)
    {
        int id = hashFn(key);
        Node<T> *n = new Node<T>(key, value);

        //insert at head of the ll with id
        n->next = table[id];
        table[id] = n;
        current_size++;

        //rehash
        float load_factor = current_size / (1.0 * table_size);
        if (load_factor > 0.7)
        {
            rehash();
        }
    }

    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Bucket " << i << "->";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << "\n";
        }
    }

    T *search(string key)
    {
        int id = hashFn(key);
        Node<T> *temp = table[id];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &temp->value;
            }
            temp = temp->next;
        }
        return NULL;
    }

    // void delete(string key){
    //     int id = hashFn(key);

    //     list <int> :: iterator i;
    //     for (i = table[id].begin(); i != table[id].end(); if (*i == key))
    //         break;
    //     if (i != table[id].end()){
    //         table[id].erase(i);
    //     }
    // }

    T &operator[](string key)
    {
        T *f = search(key);
        if (f == NULL)
        {
            //insert key, value(garbage) in the hashmap
            T garbage;
            insert(key, garbage);
            f = search(key);
        }
        return *f;
    }
};