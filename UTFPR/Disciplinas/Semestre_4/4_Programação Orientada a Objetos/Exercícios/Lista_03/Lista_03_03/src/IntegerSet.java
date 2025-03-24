public class IntegerSet {
    private boolean[] a;

    public IntegerSet(){
        a = new boolean[101];
    }

    public IntegerSet union(IntegerSet x){
        IntegerSet z = new IntegerSet();

        for(int i = 0; i < 101; i++){
            if(a[i] == true || x.a[i] == true){
                z.a[i] = true;
            }
            else{
                z.a[i] = false;
            }
        }
        return z;
    }

    public IntegerSet intersection(IntegerSet x){
        IntegerSet z = new IntegerSet();

        for(int i = 0; i < 101; i++){
            if(a[i] == true && x.a[i] == true){
                z.a[i] = true;
            }
            else{
                z.a[i] = false;
            }
        }
        return z;
    }

    public void insertElement(int k){
        a[k] = true;
    }

    public void deleteElement(int m){
        a[m] = false;
    }

    public String toSetString(){
        String str = "";

        for(int i = 0; i < 101; i++){
            if(a[i] == true){
                str = str + i + " ";
            }
        }

        //a funcao equals compara o conteudo da string e retorna true caso a condisao seja verdade
        if(str.equals("")){
            str = "--";
        }
        return str;
    }

    public boolean isEqualTo(IntegerSet x){

        for(int i = 0; i < 101; i++){
            if(a[i] != x.a[i]){
                return false;
            }
        }

        return true;
    }
}
