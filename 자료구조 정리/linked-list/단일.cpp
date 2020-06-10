class IntElement{
	public:
		IntElement(int value): next(NULL), data(value){}
		~IntElement(){}
		
		IntElement *getNext() const {return next;}
		int value() const {return data;}
		void setNext(IntElement *elem){
			next = elem;
		}
		void setValue(int value){
			data = value;
		}
		
	private:
		IntElement *next;
		int data;
};
