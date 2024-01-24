import java.util.ArrayList;

public class Banco {
    private ArrayList<Conta> listaDeContas=new ArrayList<Conta>();

    public void adcionarConta(Conta c){
        this.listaDeContas.add(c);
    }

    public String listarContas(){
        String contas="Os dados da conta são\n";

        for(Conta c:this.listaDeContas){
            contas+="Agência: "+c.getAgencia()+"\n"+
            "Conta: "+c.getAgencia()+"\n"+
            "Saldo: "+c.getSaldo()+"\n"+
            "Nome do titular: "+c.getTitular().getNome()+"\n"+
            "CPF do titular: "+c.getTitular().getCpf()+"\n"+
            "Data de nascimento do titular: "+c.getTitular().getDataNascimento();
        }
        return contas;
    }

    public Conta encontraConta(int agencia, int numero) {
            for(Conta c:this.listaDeContas){//Conta c = usupadora
                if(c.getAgencia() == agencia && c.getNumero()==numero){
                    return c;
                }
            }
        return null;
    }
}
