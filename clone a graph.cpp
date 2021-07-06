
class Solution {
public:
    void dfs(Node *node,Node * copy,map<Node *,Node *>&mp){
        if(node==NULL)
            return;
     
        mp[node]=copy;
        for(int i=0;i<node->neighbors.size();i++){
            if(mp[node->neighbors[i]]==NULL){
                Node * t=new Node(node->neighbors[i]->val);
                copy->neighbors.push_back(t);
                dfs(node->neighbors[i],copy->neighbors[i],mp);
            }
            else {
               copy->neighbors.push_back(mp[node->neighbors[i]]) ;
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
      map<Node *,Node *>mp;
        
        Node * copy=new Node();
         copy->val=node->val;
        dfs(node,copy,mp);
        return copy;
    }
};
