#include <ostream>
#include <ostream>
#include "List.H"
#include "Node.h"

template <typename T>
class ListLinked : public List<T>  {
	private:
        Node<T>x first;
	int n;

	public:
	ListLinked();
	~ListLinked();
	T operator[](int pos);
	friend std::ostream& operator<<(ostream &out,const ListLinked<T> &list);
};
