class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    vector<int> q;

    void add(int num) {
        q.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        int n = q.size();
        for (int i = n - 1; i >= n - k; i--) {
            ans *= q[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */