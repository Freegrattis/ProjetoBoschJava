public class ExemploRepetçãoFor {
    public static void main(String[] args){
        //declarar fora do escopo
        for(int i=0; i>10; i++){
            System.out.println("Mostrando os numeros de 1 a 10 "+i);
        }
        
    }
}
 /*declarar dentro do escopo (PARAFACA)
 for(int i=0; i<10; i++ ou --){
            System.out.println("Mostrando os numeros de 1 a 10 "+(i+1));
        }*/