class ProductOfNumbers {
    public:
        vector<int> prefixProduct;
        ProductOfNumbers() {
            
        }
        
        void add(int num) {
            int len = prefixProduct.size();
            if(num == 0)
                prefixProduct.resize(0);
            else{
                if(len == 0)
                    prefixProduct.push_back(num);
                else
                    prefixProduct.push_back(num * prefixProduct[len-1]);
            }
        }
        
        int getProduct(int k) {
            int len = prefixProduct.size();
            if(k == len)
                return prefixProduct[len - 1];
            else if(k > len)
                return 0;
            else
                return prefixProduct[len - 1] / prefixProduct[len - k - 1];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */