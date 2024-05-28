class Avto 
{
	int kpass;
	int vfuel;
	double cons;
	String type;

	void range() 
	{
		System.out.println("Автомобиль проедет " + vfuel/cons*100 + "км, на полном баке");
	}
}

class Obj1
{
	public static void main(String args[])
	{
		Avto nissan = new Avto();
		Avto ford = new Avto();
		Avto bmw = new Avto();
		nissan.kpass = 7;
		ford.kpass = 5;
		bmw.kpass = 2;
		nissan.type = "Минивэн";
		ford.type = "Седан";
		bmw.type = "Кабриолет";
		nissan.vfuel = 50;
		ford.vfuel = 40;
		bmw.vfuel = 20;
		nissan.cons = 12.5;
		ford.cons = 10.2;
		bmw.cons = 18.5;
		System.out.println("Информация об автомобиле \"Ниссан\"");
		System.out.println("Количество пассажиров: " + nissan.kpass);
		System.out.println("Емкость топливного бака: " + nissan.vfuel);
		System.out.println("Тип кузова: " + nissan.type);
		nissan.range();
		//System.out.println("Информация об автомобиле \"Форд\"");
		//System.out.println("Информация об автомобиле \"БМВ\"");

	}
}
