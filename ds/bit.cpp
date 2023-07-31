// TODO: Adicionar mais funções aqui
ll fen[maxn];
void add(int idx, ll val){
    while(idx<maxn){
        fen[idx] += val;
        idx += lsb(idx);
    }
}
ll query(int idx){
    ll val = 0;
    while(idx){
        val += fen[idx];
        idx -=lsb(idx);
    }
    return val;
}
 
