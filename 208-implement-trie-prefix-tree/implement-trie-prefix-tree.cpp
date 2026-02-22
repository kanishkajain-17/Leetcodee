class Trie {
public:
    struct trieNode{
        trieNode* children[26];
        bool isEndofWord;
    };
    trieNode* getNode(){//making newNode for trie
        trieNode* newNode = new trieNode();
        newNode->isEndofWord = false;

        for(int i = 0; i < 26; i++)
            newNode->children[i] = NULL;
            //ek letter ka ek vector banaya phir uske saare children ko null se intitialize kar rahe hai

        return newNode;//newNode ban gayi jisme uska 26 letters ka ek vector ban gaya jo sab null se filled hai plus uss newNode ka endWord bhi abhi false mark kar diya 
    }
    /** Initialize your data structure here. */
    trieNode* root;
    Trie() {
        root = getNode();//root ban jayegi
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode* crawler = root;

        for(int i = 0; i < word.length(); i++){//apple

            int idx = word[i] - 'a';//a
            if(!crawler->children[idx])//a ka index null hai mtlb vo node nahi bani hui toh uski node banao(a ke)

                crawler->children[idx] = getNode();

            crawler = crawler->children[idx];//moving crawler forward
        }
        crawler->isEndofWord = true; //saare letter complete toh ab last letter ko true krdo (e ko)
    }
    

     /** Returns if the word is in the trie. */
    bool search(string word) {//apple

          trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int idx = word[i] - 'a'; 
            if (!crawler->children[idx]) 
                return false; 
            crawler = crawler->children[idx]; 
        }
        return (crawler != NULL && crawler->isEndofWord); 
    }
    

     /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) { //app

        trieNode *crawler = root;
        int i = 0;
        for (i = 0; i < prefix.length(); i++) { 
            int index = prefix[i] - 'a'; 
            
            if (!crawler->children[index]) 
                return false; 
            
            crawler = crawler->children[index]; 
        }
        if(i==prefix.length())//last tak pahuch gaye mtlb mil gaya
            return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */