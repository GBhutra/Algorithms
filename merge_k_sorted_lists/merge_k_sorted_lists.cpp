#include<iostream>
#include<vector>

template<class T>
class node_t  {
public:
    node_t (T val) : value(val), next(NULL) {};
    T value;
    node_t* next;
};

template<typename T>
class list_t  {
public:
    list_t(node_t<T>* start): head(start) {};
    list_t(): head(NULL) {};
    void createListFromVector(std::vector<T>& arr);
    void addToList(node_t<T>* Node)   {
        if (head)
            head = Node;
        else    {
            node_t<T>* it = head;
            while (it->next)    {
                it = it->next;
            }
            it->next = Node;
        }
    };
    void print();
    ~list_t()   {
        if(head)    {
            node_t<int>* it = head->next;
            delete head;
            while (it->next)    {
                node_t<int>* it1 = it->next;
                delete it;
                it = it1;
            }
            delete it;
        }   
    };
private:
    node_t<T>* head;
};


template <typename T>
void list_t<T>::createListFromVector(std::vector<T>& arr)  {
    node_t<T>* it;
    if (head)   {
        it = head->next;
        while(it->next)
            it = it->next;
        it = it->next;
    }
    else    {
        it = head;
    }
    for(int i=0;i<arr.size();++i)   {
        node_t<T>* temp = new node_t<T>(arr[i]);
        it=temp;
        if (!it->next)
            std::cout<<"it="<<it->value<<std::endl;
        it=it->next;
        std::cout<<"Debug:"<<i<<" temp="<<temp->value<<std::endl;
        print();
    }
}



template <typename T>
void list_t<T>::print() {
    if(head)    {
        std::cout<<head->value<<", ";
        node_t<int>* it = head->next;
        while (it->next)    {
            std::cout<<it->value<<", ";
            it = it->next;
        }
        std::cout<<it->value<<std::endl;
    }
}

int main()  {
    node_t<int>* first = new node_t<int>(1);
    node_t<int>* second = new node_t<int>(2);
    node_t<int>* third = new node_t<int>(3);
    
    first->next = second;
    second->next = third;
    list_t<int> linked_list(first);
    linked_list.print();
    
    std::vector<int> arr {1,2,3,4,5,6,7,8,9};
    list_t<int> linked_listInt;
    linked_list.createListFromVector(arr);
    linked_list.print();
    
return 0;
}