template<class T>
class ListElement{
	public:
		ListElement(const T &value): next(NULL), data(value){
		}
		~ListElement(){
		}
		
		ListElement *getNext() const {return next;}
		const T& value() const {return data;}
		void setNext(ListElement* elem){
			next = elem;
		}
		void setValue(int value){
			data = value;
		}
	private:
		ListElement *next;
		T data;
};
