public class Principal {
    public static void main(String[] args) {
        Double num1 = EntradaSaida.pedirNumero("1º");
        Double num2 = EntradaSaida.pedirNumero("2º");
        double resultado = 0;
        boolean opcaoInvalida=false;
            int opcao = EntradaSaida.pedirOperacao();
        switch (opcao) {
            case 1:
                resultado = Calculo.somar(num1, num2);
                break;
            case 2:
                resultado = Calculo.subtrair(num1, num2);
                break;
            case 3:
                resultado=Calculo.multiplicar(num1, num2);
                break;
            case 4:
            if (num2!=0){
                resultado=Calculo.dividir(num1, num2);
            }else{
                EntradaSaida.mostrarMsg("A divisão não pode ser calculada.");
            }
                break;
            default:
            EntradaSaida.mostrarMsg("Operação inválida.");
            opcaoInvalida=true;
        }
        if((num2!=0 && opcao!=4) && opcaoInvalida == false || opcao<4){
            EntradaSaida.mostrarResultado(num1, num2, opcao, resultado);
        }else{
            
        }
        
    }
}