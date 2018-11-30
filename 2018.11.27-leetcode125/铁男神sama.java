char[] charArray = s.toCharArray();
       StringBuilder sb = new StringBuilder();
        for(char c:charArray){
            if(Character.isDigit(c)||Character.isLetter(c)){
                sb.append(c);
            }
            
        }
        
       return sb.toString().toLowerCase().equals(sb.reverse().toString().toLowerCase());
        
    }
