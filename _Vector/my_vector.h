template <typename T>
class myvector{
private:
	T *arr;
	int cs,ms;   //cs->current size      ms-max size
public:
	myvector(){
		cs=0;
		ms=1;
		arr=new T[ms];
	}

	void push_back(const T a){
		if(cs==ms){
			//copy the old array to a new array having double capacity
			T *old_arr=arr;
			ms=2*ms;
			arr=new T[ms];
			for(int i=0;i<cs;i++)
				arr[i]=old_arr[i];

			delete [] old_arr;
		}
		arr[cs]=a;
		cs++;
	}

	void pop_back(){
		cs--;
	}

	int size() const{return cs;	}

	int capacity() const{ return ms;}

	void clear(){ cs=0;}

	bool empty() {
		return cs==0;
	}

	T front() const{
		return arr[0];
	}

	T at(const int i){
		return arr[i];
	}

	//operatoe overloading
	T operator[](const int i){
		return arr[i];
	}

	T back(){
		return arr[cs-1];
	}

};