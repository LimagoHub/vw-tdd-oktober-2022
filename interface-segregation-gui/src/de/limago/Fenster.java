package de.limago;

import java.awt.*;
import java.awt.event.*;

public class Fenster extends Frame {


    public Fenster()  {

        setSize(300, 300);
        addWindowListener(new MyWindowListener());
        Button button = new Button("Drück mich");
        button.addActionListener(e->System.out.println("Button wurde gedrueckt"));
        add(button);
    }


    public static void main(String[] args) {
	    new Fenster().setVisible(true);
    }

    class MyWindowListener extends WindowAdapter {
        @Override
        public void windowClosing(WindowEvent e) {
            dispose();
        }
    }


}
