// TODO: Verificar
ll values[maxn];
ll lazy[maxn];
 
template<typename T>
struct SegTree{
	struct Node{
		int ini, fim;
	}tree[maxn];
	T *values;
	T *lazy; 
 
	std::vector<T> initValues;
	T identity;
 
	T fun(T a, T b){ // operação
		return a + b;
	}
 
	T build(int idx, int ini, int fim);
	T get(int idx, int ini, int fim);
	T add(int idx, int ini, int fim, T nvalue);
 
	T get(int idx, int index){ return get(idx,index,index); }
	T add(int idx, int index) { add(idx,index,index); }
 
	void prop(int idx);
};
 
template<typename T>
T SegTree<T>::build(int idx, int ini, int fim){
	tree[idx].ini = ini;
	tree[idx].fim = fim;
	if(ini==fim) return values[idx] = initValues[ini];
	int m = (ini+fim)/2;
	return values[idx] = fun(build(idx*2,ini, m), build(idx*2+1, m+1,fim));
}
template<typename T>
T SegTree<T>::get(int idx, int ini, int fim){
	prop(idx);
	if(tree[idx].fim < ini || tree[idx].ini > fim) return identity;
	if(ini <= tree[idx].ini && tree[idx].fim <= fim) return values[idx];
	return fun(get(2*idx,ini,fim), get(2*idx+1,ini,fim));
}
 
template<typename T>
T SegTree<T>::add(int idx, int ini, int fim, T value){
	prop(idx);
	if(tree[idx].fim < ini || tree[idx].ini > fim) return values[idx];
	if(ini <= tree[idx].ini && tree[idx].fim <= fim) {
		lazy[idx] = value;
		return fun(values[idx], value);
	}
	return values[idx] = fun(add(2*idx, ini, fim, value), add(2*idx+1,ini,fim,value));
}
template<typename T>
void SegTree<T>::prop(int idx){
	if(lazy[idx] == identity) return;
	values[idx] = fun(values[idx], lazy[idx]);
	if(2*idx < maxn)
		lazy[idx*2] = fun(lazy[2*idx], lazy[idx]);
	if(2*idx+1<maxn) 
		lazy[idx*2+1] = fun(lazy[2*idx+1], lazy[idx]);
	lazy[idx] = identity;
}
