abstract class Character 
{
	private String charclass;
	private int hp;
	private int mp;
	private int strength;
	private int stamina;

	Character()
	{
		charclass = "none";
		hp = mp = strength = stamina = 0;
	}

	Character(String chcl, int h, int m, int st, int stam)
	{
		charclass = chcl;
		hp = h;
		mp = m;
		strength = st;
	        stamina	= stam;
	}

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

	abstract double dmg();
	abstract double speed();
}

class Knight extends Character
{
	private String armor;
	Knight(String chcl, int h, int m, int st, int stam)
	{
		super("Рыцарь", h, m, st, stam);
	}
	double dmg()
	{
		return getHP() * 0.5 + getStrength();
	}

	double speed()
	{
		return getStamina() - (getStamina() * 0.2);
	}

}

class Mage extends Character
{
	String robe;
	Mage(String chcl, int h, int m, int st, int stam)
        {
                super("Маг", h, m, st, stam);
        }

        double dmg()
        {
                return getMP() * getStrength();
        }

        double speed()
        {
		return getStamina() / 1.5;
	}

}

class Thief extends Character
{
	String coin;
	Thief(String chcl, int h, int m, int st, int stam)
        {
                super("Вор", h, m, st, stam);
        }

	double speed()
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
	String fists;
	Monk(String chcl, int h, int m, int st, int stam)
        {
                super("Монах", h, m, st, stam);
        }
        double dmg()
        {
                return getMP() * 0.5 + (getStrength() * (getStamina() / 3));
        }

        double speed()
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

		for(int i = 0; i < cls.length; i++)
		{
			System.out.println("Класс персонажа: " + cls[i].getChClass());
			System.out.println();
			cls[i].showChar();
			System.out.println("\nУрон: " + cls[i].dmg());
			System.out.println("Скорость: " + cls[i].speed());
			System.out.println("------------------");
		}
	}
}
