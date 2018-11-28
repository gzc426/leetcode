class Solution{
     /*
     1.count=0;
     2.循环内，如果不是最后一个元素，获取两个值，count++;如果是最后一个元素，跳转到第5步
     3.如果前一个值和下一个值相等，删除下一个值，数量加1,指针返回到前面，跳转到第2步
       如果不相等，看count数值，
     4.数值大于1，指针到后面，添加新元素，count=0;跳转到第2步
       如果不大于1，count=0;跳转到第2步，
     5.循环外，count大于1就添加新元素
     6.返回新数组长度
     */
    public static int compress(Vector<Character> chars){
        int count=0;
        char c1;
        char c2;
        for (int i = 0; i < chars.size()-1; i++) {
            c1=chars.get(i);
            count++;
            c2=chars.get(i+1);
            if(c1==c2){
                chars.remove(i);
                i--;
            }else{//不相等
                if(count>1){//添加新元素，如：'1','5'等
                    if(count<10){
                    }else if(count>=10&&count<100){
                        chars.add(i+1,(char) (count/10%10+48));
                    }else if(count>=100&&count<1000){
                        chars.add(i+1,(char) (count/100+48));
                        chars.add(i+1,(char) (count/10%10+48));
                    }else if(count>=1000&&count<10000){
                        chars.add(++i,(char) (count/1000+48));
                        System.out.println(chars.get(i+1));
                        chars.add(++i,(char) (count/100%10+48));
                        chars.add(++i,(char) (count/10%10+48));
                    }
                    chars.add(i+1,(char) (count%10+48));
                }
                count=0;
            }
        }
        count++;
        if(count>1){
            if(count<10){
            }else if(count>=10&&count<100){
                chars.add((char) (count/10%10+48));
            }else if(count>=100&&count<1000){
                chars.add((char) (count/100+48));
                chars.add((char) (count/10%10+48));
            }else if(count>=1000&&count<10000){
                chars.add((char) (count/1000+48));
                chars.add((char) (count/100%10+48));
                chars.add((char) (count/10%10+48));
            }
            chars.add((char) (count%10+48));
            count=0;
        }
        System.out.println(chars);
        return chars.size();
    } 
    
    //测试运行
    public static void main(String[] args) {
        char[] c = new char[1200];
        c[0]='a';
        c[1]='c';
        c[2]='c';
        for (int i = 3; i < 1198; i++) {
            c[i]='g';
        }
        c[1198]='c';
        c[1199]='c';
        Vector<Character> chars= new Vector<>();
        for (int i = 0; i < c.length; i++) {
            chars.add(c[i]);
        }
       int n= compress(chars);
        System.out.println("新数组长度："+n);
    }
  }
