public class hello {
	private String name;
	public hello(String x){
		name=x;
	}

	public void say(){
		System.out.println("Hello"+name);
	}
}

class Test{
	public static void main(){
		hello ahello=new hello("Spicy_Pot");
		ahello.say();
	}

}
