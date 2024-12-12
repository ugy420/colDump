import javax.swing.*;
import java.time.LocalDate;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class minip implements ActionListener{
    JTabbedPane jtp = new JTabbedPane();
    JFrame fr = new JFrame("MyTheater");
    JPanel pn,pn1,pc1,pc2;
    JLabel jltitle,jlno,jlph,jlca,jlun,jlpw,jlm1,jlm2,jlm3,jlai;
    JTextField jtun,jtpw,jtph;
    JComboBox<String> jcmovie;
    JComboBox<Integer> jcno;
    JButton jbsub,jbres,jbgo,jbr1;
    JTextArea jtm1,jtm2,jtm3;
    ImageIcon img;

    public minip(){
        JPanel mainpanel = new JPanel();
        pn = new JPanel();
        pn1 = new JPanel();
        pc1 = new JPanel();
        pc2 = new JPanel();

        LocalDate dt = LocalDate.now(); // displaying current date
        System.out.println("Date: "+dt);

        pn.setLayout(new GridLayout(0,5));

        img = new ImageIcon("mv.png"); 

        jltitle = new JLabel("Select Movie: ");
        jlno = new JLabel("Select Seat Number: ");
        jlph = new JLabel("Enter Phone Number: ");
        jlca = new JLabel("Currently Screening: ");
        jlai = new JLabel(img);     // imporing picture in JLabel

        jcmovie = new JComboBox<String>();
        jcmovie.addItem("");
        jcmovie.addItem("Lunana: A Yak In The Classroom");
        jcmovie.addItem("The Batman");
        jcmovie.addItem("Spirited Away");

        jcno = new JComboBox<Integer>();    // creating 1-7 seats
        for(int i=1;i<=7;i++){
            jcno.addItem(i);
        }

        jtph = new JTextField(10);
        jtph.setText("");

        jbsub = new JButton("Submit");
        jbres = new JButton("Reset");

        pn.add(jltitle);
        pn.add(jcmovie);
        pn.add(new JLabel("")); // new JLabel("") is used for alignling in Grid Layout
        pn.add(jlno);
        pn.add(jcno);
        pn.add(jlph);
        pn.add(jtph);
        pn.add(new JLabel(""));
        pn.add(jlca);
        pn.add(jlai);
        pn.add(new JLabel(""));
        pn.add(new JLabel(""));
        pn.add(jbsub);
        pn.add(jbres);

        jbsub.addActionListener(this);
        jbres.addActionListener(this);

        // for Log In tab
        jlun = new JLabel("Username: ");
        jlpw = new JLabel("Password: ");
        jtun = new JTextField(10); 
        jtpw = new JTextField(10);
        jbgo = new JButton("Enter");

        pn1.add(jlun);
        pn1.add(jtun);
        pn1.add(jlpw);
        pn1.add(jtpw);
        pn1.add(jbgo);
        jbgo.addActionListener(this);
        
        // check booked seats
        pc1.setLayout(new GridLayout(3,2));
        
        jlm1 = new JLabel("Lunana: A Yak In The Classroom: ");
        jlm1.setOpaque(true);
        jlm1.setBackground(Color.white);
        jtm1 = new JTextArea(10,10);
        jlm2 = new JLabel("The Batman: ");
        jtm2 = new JTextArea(10,10);
        jlm2.setOpaque(true);
        jlm2.setBackground(Color.lightGray);
        jtm2.setBackground(Color.lightGray);
        jlm3 = new JLabel("Spirited Away");
        jtm3 = new JTextArea(10,10);
        jlm3.setOpaque(true);
        jlm3.setBackground(Color.white);
        jbr1 = new JButton("Refresh");
        
        pc1.add(jlm1);
        pc1.add(jlm2);
        pc1.add(jlm3);
        pc1.add(jtm1);
        pc1.add(jtm2);
        pc1.add(jtm3);
        pc1.add(new JLabel("Note: Seats shown here are booked!"));
        pc1.add(new JLabel(""));
        pc1.add(jbr1);
        jbr1.addActionListener(this);

        // adding panels to Tabbed Pane
        jtp.addTab("Home",pn);
        jtp.addTab("Check seats",pc1);
        jtp.addTab("Log In",pn1);
        mainpanel.add(jtp); // adding tabbed pane to main JPanel

        fr.add(mainpanel); // adding main JPanel to JFrame
        fr.setSize(1400,650);
        fr.setVisible(true);
        fr.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    JLabel jlsn,jlmvn;
    JButton jbsr,jbdl;
    JTextArea jta;
    JComboBox<String> jcm;
    JComboBox<Integer> jcn;
    public void admin(){
        JFrame jfa = new JFrame();  // creating another JFrame to be displayed in another window

        JPanel pna = new JPanel();
        pna.setLayout(null);

        jlsn = new JLabel("Seat Number: ");
        jlmvn = new JLabel("Movie Name: ");
        jbsr = new JButton("Search");
        jbdl = new JButton("Delete");
        jta = new JTextArea();

        jcm = new JComboBox<String>();
        jcm.addItem("Lunana: A Yak In The Classroom");
        jcm.addItem("The Batman");
        jcm.addItem("Spirited Away");

        jcn = new JComboBox<Integer>();
        for(int i=1;i<=7;i++){
            jcn.addItem(i);
        }

        jlsn.setBounds(5,5,100,100);   // when using null layout, the bounds should be set for each element for it to be displayed
        jcn.setBounds(110,20,55,50);
        jlmvn.setBounds(200,5,100,100);
        jcm.setBounds(275,20,225,50);
        jta.setBounds(10,100,500,200);
        jbsr.setBounds(350,310,75,50);
        jbdl.setBounds(435,310,75,50);

        pna.add(jlsn);
        pna.add(jcn);
        pna.add(jlmvn);
        pna.add(jcm);
        pna.add(jta);
        pna.add(jbdl);
        pna.add(jbsr);
        jfa.add(pna);

        jbsr.addActionListener(this);
        jbdl.addActionListener(this);

        jfa.setLocationRelativeTo(null);
        jfa.setSize(540,450);
        jfa.setVisible(true);
        jfa.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent ae){
        String s = ae.getActionCommand();
        String m = (String) jcmovie.getSelectedItem(); // Converting selected data from jcmovie into String 
        int t = (int) jcno.getSelectedItem();          // COnverting selected data from jcno to integer
        String ph = jtph.getText();
        Connection con;
        Statement stmt;
        ResultSet rs;

        if(s.equals("Submit") && m!="" && ph.length()==8){
            try{
                con=DriverManager.getConnection("jdbc:mysql://localhost:3306/mytheater","root",""); // connecting to jdbc
                stmt=con.createStatement(); // creating statement
                String query = "INSERT into biz (MovieName, SeatNumber, PhoneNumber) VALUES ('"+m+"','"+t+"','"+ph+"')";
                if(stmt.executeUpdate(query)>=1){
                    System.out.println("Details Submitted!");
                    jcmovie.setSelectedIndex(0);
                    jcno.setSelectedItem(1);
                    jtph.setText("");
                }else
                    System.out.println("Failed to Submit!");
            }
            catch(Exception e){
                System.out.println("Error while connecting to database: "+e);
            }
        }
        else if(s.equals("Submit") && (m=="" || ph.length()==0)){
            System.out.println("One or more fields are left empty");
        }
        else if(s.equals("Submit") && ph.length()!=8){
            System.out.println("Enter a valid 8 digit phone number!");
        }
        else if(s.equals("Reset")){
            jcmovie.setSelectedItem("");
            jcno.setSelectedIndex(0);
            jtph.setText("");
        }

        if(s.equals("Enter") && jtun.getText().equals("Admin") && jtpw.getText().equals("password")){ // Username: Admin | Password: password
            admin();
        }
        else if(s.equals("Enter") && jtun.getText()!="a" && jtpw.getText()!="b"){
            System.out.println("Wrong username or password");
        }

        if(s.equals("Refresh")){
            try{
                con=DriverManager.getConnection("jdbc:mysql://localhost:3306/mytheater","root","");
                stmt = con.createStatement();
                String str = "",stra = "",strb = "";
                for(int num=1;num<=7;num++){    // updates the textarea if the seats are already booked i.e data exists in the biz table
                    String query = "SELECT * FROM biz WHERE SeatNumber='"+num+"' AND MovieName='Lunana: A Yak In The Classroom'";
                    rs = stmt.executeQuery(query);
                    if(rs.next()){
                        str += "|"+String.valueOf(rs.getInt("SeatNumber"))+"|\n";
                        jtm1.setText(str);
                    }

                    String puery = "SELECT * FROM biz WHERE SeatNumber='"+num+"' AND MovieName='The Batman'";
                    ResultSet rsa = stmt.executeQuery(puery);
                    if(rsa.next()){
                        stra += "|"+String.valueOf(rsa.getInt("SeatNumber"))+"|\n";
                        jtm2.setText(stra);
                    }

                    String ouery = "SELECT * FROM biz WHERE SeatNumber='"+num+"' AND MovieName='Spirited Away'";
                    ResultSet rsb = stmt.executeQuery(ouery);
                    if(rsb.next()){
                        strb += "|"+String.valueOf(rsb.getInt("SeatNumber"))+"|\n";
                        jtm3.setText(strb);
                    }
                }
            }
            catch(Exception e){
                System.out.println("Error while reading "+e);
            }
        }

        if(ae.getSource()==jbdl){ // deletes the data from the database using the seatnumber and moviename conditions
            try{
                con=DriverManager.getConnection("jdbc:mysql://localhost:3306/mytheater","root","");
                stmt = con.createStatement();
                String query = "DELETE FROM biz WHERE SeatNumber='"+(Integer) jcn.getSelectedItem()+"' AND MovieName='"+(String) jcm.getSelectedItem()+"'";
                stmt.executeUpdate(query);
                jta.setText("Data Deleted!");
            }
            catch(Exception e){
                System.out.println("Deletion failed " + e);
            }
        }
        if(ae.getSource()==jbsr){ // searches the data on conditions set by the user
            try{
                con=DriverManager.getConnection("jdbc:mysql://localhost:3306/mytheater","root","");
                stmt = con.createStatement();
                String query = "SELECT * FROM biz WHERE SeatNumber='"+(Integer) jcn.getSelectedItem()+"' AND MovieName='"+(String) jcm.getSelectedItem()+"'";
                rs = stmt.executeQuery(query);
                
                String str="";
                if(rs.next()){
                    String phn = rs.getString("PhoneNumber");
                    str = "Seat Number: "+(Integer) jcn.getSelectedItem()+"\nMovie Name: "+(String) jcm.getSelectedItem()+"\nPhone Number: "+phn;
                    jta.setText(str);
                }
                else{
                    jta.setText("Data does not exist!");
                }
            }
            catch(Exception e){
                System.out.println("Search failed " + e);
            }
        }
    }
    public static void main(String[] args){
        new minip();
    }
}