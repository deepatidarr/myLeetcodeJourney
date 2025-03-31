class FileSystem {
    struct Node{
        unordered_map<string,Node*> children;
        string content = "";
        bool isFile = false;

        // void put(string s, Node* node){
        //     mp[s] = node;
        // }
        // Node* get(string dir){
        //     return mp[dir];
        // }
        // bool containsFile(string file){
        //     if(mp.find(file)==mp.end()) return false;
        //     return true;
        // }
        // unordered_map<string,Node*> getData(){
        //     return mp;
        // }
        // void addContent(string s){
        //     content += s;
        // }
        // string getContent(){
        //     return content;
        // }
    };
    Node *root;
public:
    FileSystem() {
        root = new Node();
        //root->put("/", new Node());
    }
    vector<string> splitPath(const string& path) {
        vector<string> parts;
        stringstream ss(path);
        string part;
        while (getline(ss, part, '/')) {
            if (!part.empty()) parts.push_back(part);
        }
        return parts;
    }
    vector<string> ls(string path) {
        Node* node = root;
        vector<string> parts = splitPath(path); // Implement this helper
        
        for (const string& part : parts) {
            if (!node->children.count(part)) return {};
            node = node->children[part];
        }
        
        if (node->isFile) return {parts.back()}; // File case
        
        vector<string> res;
        for (auto& [name, _] : node->children) res.push_back(name);
        sort(res.begin(), res.end());
        return res;
        // Node* node = root;
        // for(int i=0; i<path.size(); i++){
        //     if(path[i]=='/') continue;
        //     string tmp="";
        //     while(path[i]!='/' && i<path.size()){
        //         tmp += path[i];
        //         i++;
        //     }
        //     if(node->containsFile(tmp)){
        //         node = node->get(tmp);
        //     }
        // }
        // vector<string> res;
        // for(auto &it: node->getData()){
        //     res.push_back(it.first);
        // }
        // return res;
    }
    
    void mkdir(string path) {
        Node* node = root;
        vector<string> parts = splitPath(path); // Split into components
        
        for (const string& part : parts) {
            if (!node->children.count(part)) {
                node->children[part] = new Node(); // Create new directory
            }
            node = node->children[part];
        }
    }
    
    void addContentToFile(string path, string content) {
        Node* node = root;
        vector<string> parts = splitPath(path);
        
        // Traverse all but last part (must be directories)
        for (int i = 0; i < parts.size() - 1; i++) {
            if (!node->children.count(parts[i])) {
                node->children[parts[i]] = new Node(); // Create directory
            }
            node = node->children[parts[i]];
        }
        
        // Handle file
        string filename = parts.back();
        if (!node->children.count(filename)) {
            node->children[filename] = new Node();
            node->children[filename]->isFile = true;
        }
        node->children[filename]->content += content;
        // Node* node = root;
        // for(int i=0; i<path.size(); i++){
        //     if(path[i]=='/') continue;
        //     string tmp;
        //     while(path[i]!='/' && i<path.size()){
        //         tmp += path[i];
        //         i++;
        //     }
        //     if(!node->containsFile(tmp)){
        //         node->put(tmp, new Node());
        //     }
        //     node = node->get(tmp);
        // }
        // node->addContent(content);
    }
    
    string readContentFromFile(string filePath) {
        Node* node = root;
        vector<string> parts = splitPath(filePath);
        
        // Traverse all parts except last (must be directories)
        for (int i = 0; i < parts.size() - 1; i++) {
            if (!node->children.count(parts[i])) {
                return ""; // Or throw error - path doesn't exist
            }
            node = node->children[parts[i]];
        }
        
        // Check the final node
        string filename = parts.back();
        if (!node->children.count(filename) || !node->children[filename]->isFile) {
            return ""; // File doesn't exist or is a directory
        }
        
        return node->children[filename]->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
