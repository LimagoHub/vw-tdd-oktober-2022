package de.clientside;

import de.tiere.PigTooFatListener;
import de.tiere.Schwein;



public class Main {
	private Metzger metzger = new Metzger();
	private Spediteur spediteur = new Spediteur();
private Andere andere = new Andere();
	public static void main(String[] args) {
		new Main().run();

	}
	private void run() {

		Schwein piggy = new Schwein("Miss Piggy");
		piggy.addPigTooFatListener(metzger::schlachten);
		piggy.addPigTooFatListener(spediteur::fahren);
		piggy.addPigTooFatListener(e->andere.foo(e, ""));

		for (int i = 0; i < 11; i++) {
			piggy.fuettern();

		}
	}

//	class SchweineMetzgerAdapter implements PigTooFatListener {
//
//		@Override
//		public void pigTooFat(Schwein dickesSchwein) {
//			metzger.schlachten(dickesSchwein);
//		}
//	}

	class Metzger {


		public void schlachten(Object dickesSchwein) {

			System.out.println("Messer wetz!");
		}

	}

	class Spediteur {


		public void fahren(Object ware) {

			System.out.println("Wir fahren auf der Autobahn");
		}

	}


	class Andere {


		public void foo(Object ware, String ausgabe) {

			System.out.println("Wir fahren auf der Autobahn");
		}

	}


}



