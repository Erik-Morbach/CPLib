
struct Nodes{
	ll value;
	ll lazy;
	int ini, fim;
}nodes[maxn];

struct Seg{
	void build(int ini, int fim, int idx=1){
		nodes[idx].ini = ini;
		nodes[idx].fim = fim;
		nodes[idx].lazy = 0;
		if(ini == fim){
			nodes[idx].value = 0;
			return;
		}
		int m = (ini + fim)/2;
		build(ini, m, idx*2);
		build(m+1, fim, idx*2+1);
		nodes[idx].value = nodes[idx*2].value + nodes[idx*2+1].value;
	}
	ll query(int ini, int fim, int idx=1){
		prop(idx);
		if(nodes[idx].fim < ini || nodes[idx].ini > fim) return 0;
		if(ini <= nodes[idx].ini && nodes[idx].fim <= fim) return nodes[idx].value;
		return query(ini, fim, 2*idx) + query(ini, fim, 2*idx+1);
	}
	void update(int ini, int fim, int v, int idx=1){
		prop(idx);
		if(nodes[idx].fim < ini || nodes[idx].ini > fim) return;
		if(ini <= nodes[idx].ini && nodes[idx].fim <= fim) {
			nodes[idx].lazy += v;
			prop(idx);
			return;
		}
		update(ini, fim, v, 2*idx);
		update(ini, fim, v, 2*idx+1);
		nodes[idx].value = nodes[idx*2].value + nodes[idx*2+1].value;
	}
	void prop(int idx){
		if(nodes[idx].lazy == 0) return;
		if(idx*2 < maxn) nodes[idx*2].lazy += nodes[idx].lazy;
		if(idx*2+1 < maxn) nodes[idx*2+1].lazy += nodes[idx].lazy;
		nodes[idx].value += nodes[idx].lazy * (nodes[idx].fim - nodes[idx].ini + 1);
		nodes[idx].lazy = 0;
	}
}seg;








/*
// TODO: Limpar implementação
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
}*/
