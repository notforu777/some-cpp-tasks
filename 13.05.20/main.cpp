#include <bits/stdc++.h>

using namespace std;

int main(){
    set <int> st;
    st.insert(3);
    int a = *st.upper_bound(2);
    cout << a;
}
