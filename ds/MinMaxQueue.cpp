template<typename T>
T fun(const T &a, const T &b){
	return max(a,b);
}

template<typename T>
struct MMStack{
	vector<pair<T,T>> sta;
	size_t size(){
		return sta.size();
	}
	void push(T x){
		T mini = x;
		if(sta.size()) mini = fun(mini, sta.back().y);
		sta.push_back(make_pair(x, mini));
	}
	pair<T,T> get(){
		return sta.back();
	}
	void pop(){
		sta.pop_back();
	}
};

template<typename T>
struct MMQueue{
	MMStack<T> a,b;
	T sentinel;
	void push(T x){
		b.push(x);
	}
	T get(){
		if(a.size()==0 && b.size()==0) return sentinel;

		if(a.size()==0 || b.size()==0)
			return a.size()==0 ? b.get().y : a.get().y;

		return fun(a.get().y, b.get().y);
	}
	T pop(){
		if(a.size()==0){
			while(b.size()){
				a.push(b.get().x);
				b.pop();
			}
		}
		if(a.size()){
			T response = a.get().y;
			a.pop();
			return response;
		}
		return sentinel;
	}
	size_t size(){
		return a.size() + b.size();
	}
};
