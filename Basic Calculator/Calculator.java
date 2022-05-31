// Basic Calculator using AWT and Java

import java.lang.*;
import java.awt.*;
import java.awt.event.*;

// Logic class
class Demo
{
        public String DataDe()
        {
            return "Jay Ganesh...";
        }

        public int Addition(int a, int b)
        {
            return a + b;
        }

        public int subtraction(int a, int b)
        {
            return a - b;
        }
        public int multiplication(int a, int b)
        {
            return a * b;
        }

        public int division(int a, int b)
        {
            return a / b;
        }

        public int remainder(int a, int b)
        {
            return a % b;
        }
}

// frontEnd class
class MarvellousFrame extends WindowAdapter implements ActionListener
{
    public Frame fobj;
    public Button b1, b2 ,b3, b4, b5;
    public TextField tf1, tf2, tf3;
    public Label l1, l2, l3;

    public MarvellousFrame(String name)
    {
        fobj = new Frame(name);
        
        tf1 = new TextField();    
        tf1.setBounds(50, 50, 150, 20);    
        tf2 = new TextField();    
        tf2.setBounds(50, 100, 150, 20);    
        tf3 = new TextField();    
        tf3.setBounds(50, 150, 150, 20);  
  
        b1 = new Button("+");    
        b1.setBounds(50, 200, 50, 50);  
        b2 = new Button("-");    
        b2.setBounds(120,200,50,50); 
        b3 = new Button("*");    
        b3.setBounds(190, 200, 50, 50);  
        b4 = new Button("/");    
        b4.setBounds(70,270,50,50); 
        b5 = new Button("%");    
        b5.setBounds(140,270,50,50); 
        
        l1 = new Label("Enter first number :");
        l1.setBounds(50, 30, 150, 30);
        l2 = new Label("Enter second number :");
        l2.setBounds(50, 80, 150, 30);
        l3 = new Label("Result:");
        l3.setBounds(50, 130, 100, 30);

        fobj.add(tf1);  
        fobj.add(tf2);  
        fobj.add(tf3);  
        fobj.add(b1);  
        fobj.add(b2); 
        fobj.add(b3);
        fobj.add(b4);
        fobj.add(b5);  
        fobj.add(l1);
        fobj.add(l2);
        fobj.add(l3);
          
        fobj.setSize(400,400);    
        fobj.setLayout(null);    
        fobj.setVisible(true);      

        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        fobj.addWindowListener(this);
    }

    public void windowClosing(WindowEvent obj)
    {
        System.exit(0);
    }

    public void actionPerformed(ActionEvent obj)
    {
        Demo dobj = new Demo();
        if(obj.getSource() == b1)
        {
            String s1 = tf1.getText();
            String s2 = tf2.getText();

            int n1 = Integer.parseInt(s1);
            int n2 = Integer.parseInt(s2);

            int n3 = dobj.Addition(n1,n2);
            String ans = Integer.toString(n3);

            tf3.setText(ans);  
        }
        else if(obj.getSource()== b2)
        {
            String s1 = tf1.getText();
            String s2 = tf2.getText();

            int n1 = Integer.parseInt(s1);
            int n2 = Integer.parseInt(s2);

            int n3 = dobj.subtraction(n1,n2);
            String ans = Integer.toString(n3);

            tf3.setText(ans); 
        }
        else if(obj.getSource()== b3)
        {
            String s1 = tf1.getText();
            String s2 = tf2.getText();

            int n1 = Integer.parseInt(s1);
            int n2 = Integer.parseInt(s2);

            int n3 = dobj.multiplication(n1,n2);
            String ans = Integer.toString(n3);

            tf3.setText(ans); 
        }
        else if(obj.getSource()== b4)
        {
            String s1 = tf1.getText();
            String s2 = tf2.getText();

            int n1 = Integer.parseInt(s1);
            int n2 = Integer.parseInt(s2);

            int n3 = dobj.division(n1,n2);
            String ans = Integer.toString(n3);

            tf3.setText(ans); 
        }
        else if(obj.getSource()== b5)
        {
            String s1 = tf1.getText();
            String s2 = tf2.getText();

            int n1 = Integer.parseInt(s1);
            int n2 = Integer.parseInt(s2);

            int n3 = dobj.remainder(n1,n2);
            String ans = Integer.toString(n3);

            tf3.setText(ans); 
        }


    }
}

class Calculator
{
    public static void main(String arg[])
    {
        MarvellousFrame mobj = new MarvellousFrame("Calculator");
    }
}
