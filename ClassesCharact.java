abstract class Character //абстрактный класс, описывающий персонажа
{
	private String charclass; //название класса персонажа
	private int hp; //кол-во очков здоровья
	private int mp; //кол-во маны (очков магии)
	private int strength; //сила
	private int stamina; //выносливость

	Character(String chcl, int h, int m, int st, int stam)
	{
		charclass = chcl;
		hp = h;
		mp = m;
		strength = st;
	        stamina	= stam;
	}

	//методы доступа к переменным
	int getHP() { return hp; }
        int getMP() { return mp; }
        int getStrength() { return strength; }
        int getStamina() { return stamina; }
	void setHP(int h) { hp = h; }
        void setMP(int m) { mp = m; } 
	void setStrength(int st) { strength = st; } 
	void setStamina(int stam) { stamina = stam; } 	

	String getChClass() { return charclass; }

	void showChar()
	{
		System.out.println("Здоровье: " + hp  + "\nМана: " + mp + "\nСила: " + strength + "\nВыносливость: " + stamina);
	}

	abstract double dmg(); //объявление абстрактного метода, высчитывающего урон персонажа
	abstract double speed(); //объявление абстрактного метода, высчитывающего скорость персонажа
}

class Knight extends Character //подкласс Knight производный из класса Character
{
	Knight(String chcl, int h, int m, int st, int stam)
	{
		super(chcl, h, m, st, stam); //вызов конструктора суперкласса
	}
	double dmg() //реализация метода dmg в классе Knight
	{
		return getHP() * 0.5 + getStrength(); //уникальная формула высчитывания урона для класса Knight в методе dmg
	//урон зависит от количества здоровья и силы
	}

	double speed()
	{
		return getStamina() - (getStamina() * 0.2); //уникальная формула высчитывания скорости
	}

}

class Mage extends Character
{
	Mage(String chcl, int h, int m, int st, int stam)
        {
                super(chcl, h, m, st, stam);
        }

        double dmg()
        {
                return getMP() * getStrength(); //урон зависит от кол-ва маны и силы
        }

        double speed()
        {
		return getStamina() / 1.5;
	}

}

class Thief extends Character
{
	Thief(String chcl, int h, int m, int st, int stam)
        {
                super(chcl, h, m, st, stam);
        }

	double speed() //сначала реализуется метод speed, т.к. он используется для реализации метода dmg
        {
                return getStamina() * 2 - (getHP() * 0.2);
        }


        double dmg()
        {
                return getStrength() * (speed() * 0.5);
        }
}

class Monk extends Character
{
	Monk(String chcl, int h, int m, int st, int stam)
        {
                super(chcl, h, m, st, stam);
        }
        double dmg()
        {
                return getMP() * 0.5 + (getStrength() * (getStamina() / 3));
        }

        double speed() //в реализации данного метода используется метод dmg
        {
		return getStamina() * (getHP() * 0.03);
	}

}

class ClassesCharact
{
	public static void main(String args[])
	{
		Character cls[] = new Character[4];

		cls[0] = new Knight("Рыцарь", 50, 2, 10, 8); 
		cls[1] = new Mage("Маг", 20, 10, 3, 5);
		cls[2] = new Thief("Вор", 30, 4, 5, 7);
		cls[3] = new Monk("Монах", 40, 6, 6, 10);

		for(int i = 0; i < cls.length; i++) //с помощью цикла for выводим данные всех персонажей
		{
			System.out.println("Класс персонажа: " + cls[i].getChClass());
			System.out.println();
			cls[i].showChar();
			System.out.println("\nУрон: " + cls[i].dmg()); //для каждого класса вызываются соответствующие методы dmg и speed
			System.out.println("Скорость: " + cls[i].speed());
			System.out.println("------------------");
		}
	}
}
