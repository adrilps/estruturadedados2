package aula01.saidadados;

public class ExemploSaidaDados {

	public static void main(String[] args) {

		String aluno = "João da Silva";
		int periodo = 4;
		double coeficiente = 0.78;

		System.out.println(aluno + " está no " + periodo + " período e possui " + coeficiente + " de coeficiente");
		System.out.println("Programação Orientada a Objeto");

		System.out.printf("%s está no %d período e possui %.2f de coeficiente", aluno, periodo, coeficiente);
	}
}
