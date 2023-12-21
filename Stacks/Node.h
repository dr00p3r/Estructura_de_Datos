#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <typename T>
class Node{
private:
    T value;
    Node<T>* below;
public:
    Node();
    Node(T, Node<T>*);
    ~Node();
    T get_value();
    void set_value(T);
    Node<T>* get_below();
    void set_below(Node<T>*);
};

#endif // NODE_H_INCLUDED
