package aula01.saidadados;

public class ExemploSaidaDados {

	public static void main(String[] args) {

		String aluno = "Jo�o da Silva";
		int periodo = 4;
		double coeficiente = 0.78;

		System.out.println(aluno + " est� no " + periodo + " per�odo e possui " + coeficiente + " de coeficiente");
		System.out.println("Programa��o Orientada a Objeto");

		System.out.printf("%s est� no %d per�odo e possui %.2f de coeficiente", aluno, periodo, coeficiente);
	}
}
