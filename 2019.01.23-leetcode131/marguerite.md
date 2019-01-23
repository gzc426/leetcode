```
public class Solution {
    List<List<String>> res=new ArrayList<>();
    public List<List<String>> partition(String s) {
        DFS(s,new ArrayList<String>());
        return res;
    }
    private void DFS(String s,List<String> list){
		if(s.length()<1){
			res.add(new ArrayList<>(list));
			return;
		}
		for(int i=1;i<=s.length();i++){
			String str=s.substring(0, i);
			if(this.isPalindrom(str)){
				list.add(str);
				DFS(s.substring(i),list);
				list.remove(list.size()-1);
			}else{
				continue;
			}
		}
	}
	private  boolean isPalindrom(String s){
		
		int p1=0;
		int p2=s.length()-1;
		int len=(s.length()+1)/2;
		for(int i=0;i<len;i++){
			if(s.charAt(p1++)!=s.charAt(p2--))
				return false;
		}
		return true;
	}
}

```
