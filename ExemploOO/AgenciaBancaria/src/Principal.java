public class Principal {
    public static void main(String[] args) {
        Conta conta;
        int agencia=0;
        int numero=0;
        int opcao;
        Banco b = new Banco();// quero apenas 1 objeto banco
        do {
            opcao = EntradaSaida.escolherOpcaoMenu();
            switch (opcao) {
                case 1:
                    // quero varias contas
                    Conta c = new Conta();// metodo invocado na instancia de um objeto é o metodo construtor
                    c.setAgencia( EntradaSaida.solicitarDadoConta("a agência"));
                    c.setNumero (EntradaSaida.solicitarDadoConta("o numero"));
                    Pessoa p = new Pessoa();
                    p.setCpf(EntradaSaida.solicitarCpf());
                    p.setDataNascimento( EntradaSaida.solicitarDadoTitular("a data de nascimento"));
                    p.setNome( EntradaSaida.solicitarDadoTitular("o nome completo"));
                    c.setTitular(p);
                    b.adcionarConta(c);// adicionando o objeto conta na lista do objeto banco

                    break;
                case 2:
                if(!b.set.isEmpty()){
                     EntradaSaida.mostrarContas(b.listarContas());
                }else{
                    EntradaSaida.mostrarAlerta("Não há contas para mostrar no momento...");
                }
                    break;
                case 3:
                    
                    agencia = EntradaSaida.solicitarDadoConta("a agência");
                    numero = EntradaSaida.solicitarDadoConta("o numero");
                    conta=b.encontraConta(agencia,numero);
                    if(conta!=null){
                        conta.depositar(EntradaSaida.solicitarValorOperacao("depósito"));
                    }else{
                        EntradaSaida.mostrarAlerta("Agencia ou numero não encontrado");
                    }
                    break;
                case 4:
                    agencia = EntradaSaida.solicitarDadoConta("a agência");
                    numero = EntradaSaida.solicitarDadoConta("o numero");
                    conta=b.encontraConta(agencia,numero);
                    if(conta!=null){
                        conta.sacar(EntradaSaida.solicitarValorOperacao("saque"));
                    }else{
                        EntradaSaida.mostrarAlerta("Agencia ou numero não encontrado");
                    }
                    break;
                default:

                    break;
            }
        } while (opcao != 5);
    }
}
