class TextEditor {
private:
    stack<char> left, right;
public:
    TextEditor() {
       
    }
    
    void addText(string text) {
        for(int i=0; i<text.size(); i++){
            left.push(text[i]);
        }
    }
    
    int deleteText(int k) {
        int del=0;
        while(left.size() && k--){
            left.pop();
            del++;
        }
        return del;
    }
    
    string cursorLeft(int k) {
        while(left.size() && k--){
            right.push(left.top());
            left.pop();
        }
        string tmp = "";
        int a=10;
        while(left.size() && a--){
            tmp += left.top();
            left.pop();
        }
        reverse(tmp.begin(), tmp.end());
        addText(tmp);
        return tmp;
    }
    
    string cursorRight(int k) {
        while(right.size() && k--){
            left.push(right.top());
            right.pop();
        }
        string tmp = "";
        int a=10;
        while(left.size() && a--){
            tmp += left.top();
            left.pop();
        }
        reverse(tmp.begin(), tmp.end());
        addText(tmp);
        return tmp;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
