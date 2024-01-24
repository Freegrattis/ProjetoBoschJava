import javax.swing.JOptionPane;

public class ExemploSwitch {
    public static void main(String[] args) {
        int numeroDia = Integer.parseInt(JOptionPane.showInputDialog("Entre com um valor de 1 à 7."));
        while(numeroDia<1 || numeroDia>7){
            numeroDia = Integer.parseInt(JOptionPane.showInputDialog("Entre com um valor de 1 à 7."));
        }
        String diaSemana = "O dia da semana é\n";
        switch (numeroDia) {
            case 1:
                diaSemana += "Domingo";
                break;
            case 2:
                diaSemana += "Segunda-Feira";
                break;
            case 3:
                diaSemana += "Terça-Feira";
                break;
            case 4:
                diaSemana += "Quarta-Feira";
                break;
            case 5:
                diaSemana += "Quinta-Feira";
                break;
            case 6:
                diaSemana += "Sexta-Feira";
                break;
            case 7:
                diaSemana += "Sabado";
                break;
            /*default:
                diaSemana="O numero informado nao corresponde a um dia da semana";
            */
        }
        JOptionPane.showMessageDialog(null, diaSemana);
    }
}