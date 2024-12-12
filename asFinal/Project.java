import java.util.*;
import java.io.*;

public class Project
{
    static int lineNum = 0;
    static String[] province, beneficiary, beneficiaryNum, assetClass, name, stage;
    private Location location;

    static FileInputStream fileStream = null;
    static InputStreamReader rdr;
    static BufferedReader bufRdr;
    
    public static void readFile(String pFileName) 
    {
        String line;
        erFile();   // clear previous file logs.

        try 
        {
            int rows = rowsN(pFileName); // calling method rowsN which will read the file to count the number of rows.
  
            province = new String[rows];
            beneficiary = new String[rows];
            beneficiaryNum = new String[rows];
            assetClass = new String[rows];
            name = new String[rows];
            stage = new String[rows];    // initializing arrays with the number of rows in the csv file.
            
            fileStream = new FileInputStream(pFileName);    // each method needs to open the file independently to 
            rdr        = new InputStreamReader(fileStream); // perform its specific operations. Even though both
            bufRdr     = new BufferedReader(rdr);           // methods are opening the same file, they are separate
                                                            // instances of reading the file, and thus they each
                                                            // require their own instances. 
            line = bufRdr.readLine();

            while(line != null)
            {
                if(lineNum!=0){
                    processLine(line); // first row is not processed as it includes the header for the data.
                }
                lineNum++;
                line = bufRdr.readLine();
            }
            fileStream.close();
        }
        catch(IOException errorDetails) 
        {
            if(fileStream != null) 
            {
                try 
                {
                    fileStream.close();
                }
                catch(IOException ex2) 
                { }
            }
            System.out.println("Error in fileProcessing: " + errorDetails.getMessage());
        }
        menu(); // after csv file is processed, the menu program is called.
    }

    private static int rowsN(String fileName){
        int count = 0;
        try{
            fileStream = new FileInputStream(fileName);     // another instance of reading the file.
            rdr        = new InputStreamReader(fileStream);
            bufRdr     = new BufferedReader(rdr);

            while (bufRdr.readLine() != null) {
                count++;
            }
        }
        catch(IOException e){
            if(fileStream != null) 
            {
                try 
                {
                    fileStream.close();
                }
                catch(IOException ex2) 
                { }
            }
            System.out.println("Error in fileProcessing: " + e.getMessage());
        }
        return count;   // will return the value of count to the caller of the method.
    }

    private static void processLine(String csvRow)
    {
        String[] splitLine;
        splitLine = csvRow.split(",");    // each line of the csv file is split into arrays.
                                                // indexes 0-11 for province, beneficiary, beneficiaryNum and so on.

        double lat = Double.valueOf(splitLine[7]);  // index 7 & 8 are for latitude and longitude respectively,
        double lon = Double.valueOf(splitLine[8]);  // which are used to check if the data is valid or not.

        if((lat>=-90 && lat<=90) && (lon>=-180 && lon<=180)){
            province[lineNum] = splitLine[0];       // assigns the values to their respective arrays
            beneficiary[lineNum] = splitLine[1];
            beneficiaryNum[lineNum] = splitLine[2];
            assetClass[lineNum] = splitLine[3];
            name[lineNum] = splitLine[4];
            stage[lineNum] = splitLine[6];
        }
        else{
            System.out.println("Invalid data detected! Exiting program...");
            System.exit(0); // exits the program if invalid data is detected.
        }
    }

    public static void menu(){
        Scanner sc = new Scanner(System.in);
        int choice = 0;

        String prtMenu = "Welcome to the Investments in Indigenous community infrastructure Program. There are a total of " + (lineNum-1) + " projects throughout Canada. Please make a selection from the Menu below.";
        PrintAndLog(prtMenu);
        PrintAndLog("");

        dispMenu(); // displaying the menu options

        try{
            while(choice!=15){
                choice = sc.nextInt();
                switch(choice){
                    case 1:
                        cana();
                        endLine();
                        break;

                    case 2:
                        oth("Alberta");
                        break;
                
                    case 3:
                        oth("British Columbia");
                        break;
                    
                    case 4:
                        oth("Manitoba");
                        break;
                    
                    case 5:
                        oth("New Brunswick");
                        break;
                    
                    case 6:
                        oth("Newfoundland And Labrador");
                        break;
                    
                    case 7:
                        oth("Nova Scotia");
                        break;
                    
                    case 8:
                        oth("Ontario");
                        break;
                    
                    case 9:
                        oth("Prince Edward Island");
                        break;
                    
                    case 10:
                        oth("Quebec");
                        break;

                    case 11:
                        oth("Saskatchewan");
                        break;

                    case 12:
                        oth("Northwest Territories");
                        break;

                    case 13:
                        oth("Nunavut");
                        break;

                    case 14:
                        oth("Yukon");
                        break;

                    case 15:
                        String prtMenuS = "Program exited";
                        PrintAndLog(prtMenuS);
                        break; 
                        
                    default:
                        String prtMenuDef = "Choose any option between 1-15.";
                        PrintAndLog(prtMenuDef);
                        break;
                    }
            }
            sc.close();
        }
        catch(Exception e){
            String prtE = "Exception Occurred, restarting program...";
            PrintAndLog(prtE);
            endLine();
            menu();
        }
    }

    private static void dispMenu(){     // printing menu options.

        String prtDm1 = "> 1.All of Canada";
        String prtDm2 = "> 2.Alberta";
        String prtDm3 = "> 3.British Columbia";
        String prtDm4 = "> 4.Manitoba";
        String prtDm5 = "> 5.New Brunswick";
        String prtDm6 = "> 6.Newfoundland and Labrador";
        String prtDm7 = "> 7.Nova Scotia";
        String prtDm8 = "> 8.Ontario";
        String prtDm9 = "> 9.Prince Edward Island";
        String prtDm10 = "> 10.Quebec";
        String prtDm11 = "> 11.Saskatchewan";
        String prtDm12 = "> 12.Northwest Territories";
        String prtDm13 = "> 13.Nunavut";
        String prtDm14 = "> 14.Yukon";
        String prtDm15 = "> 15.Exit Program";

        PrintAndLog(prtDm1);
        PrintAndLog(prtDm2);
        PrintAndLog(prtDm3);
        PrintAndLog(prtDm4);
        PrintAndLog(prtDm5);
        PrintAndLog(prtDm6);
        PrintAndLog(prtDm7);
        PrintAndLog(prtDm8);
        PrintAndLog(prtDm9);
        PrintAndLog(prtDm10);
        PrintAndLog(prtDm11);
        PrintAndLog(prtDm12);
        PrintAndLog(prtDm13);
        PrintAndLog(prtDm14);
        PrintAndLog(prtDm15);
        PrintAndLog("");
    }

    public static void cana(){
        int tot = lineNum-1;        // total number of projects is number of rows - 1.
        int ong=0, com=0;
        for(int i=1;i<lineNum;i++){ // do not initialize i as 0 because stage[0] is null (not been assigned any value)
            if(stage[i].equals("Ongoing")){
                ong++;
            }
            else if(stage[i].equals("Completed")){
                com++;
            }
        }
        float calc = (float) (com*100)/tot;
        float per = (float) Math.round(calc*100)/100;    // displays upto 2 decimal points

        String prtCana1 = "The total number of projects in Canada: " + tot;
        String prtCana2 = "The total number of Ongoing projects: " + ong;
        String prtCana3 = "The total number of projects Completed: " + com;
        String prtCana4 = "The percentage of Completed Projects: " + per + "%";

        PrintAndLog(prtCana1);
        PrintAndLog(prtCana2);
        PrintAndLog(prtCana3);
        PrintAndLog(prtCana4);
    }

    public static void oth(String prName){  // printing options for provinces by names has been passed.
        String prtOth0 = "Please make a choice from the statistics below for " + prName + ": ";
        PrintAndLog(prtOth0);

        Scanner sc = new Scanner(System.in); // closing sc will cause problems when returning to main menu.
        int choice2 = 0;
        String prtOth1 = "> 1.Number of projects";
        String prtOth2 = "> 2.Percentage of all projects located in this province/territory";
        String prtOth3 = "> 3.Total number and percentage of Ongoing projects";
        String prtOth4 = "> 4.Total number and percentage of Completed projects";
        String prtOth5 = "> 5.All of the above statistics";
        String prtOth6 = "> 6.Return to main menu";

        PrintAndLog(prtOth1);
        PrintAndLog(prtOth2);
        PrintAndLog(prtOth3);
        PrintAndLog(prtOth4);
        PrintAndLog(prtOth5);
        PrintAndLog(prtOth6);
        PrintAndLog("");

        while(choice2!=6){

            choice2 = sc.nextInt();

            switch(choice2){
                case 1:
                    int num = op1(prName);  // counting number of projects in the region
                    String prtC1 = "Number of Projects in " + prName + ": " + num;
                    PrintAndLog(prtC1);                    
                    break;
                case 2:
                    op2(prName);
                    break;
                case 3:
                    op3(prName);
                    break;
                case 4:
                    op4(prName);
                    break;
                case 5:
                    String prtC5 = "Number of Projects in " + prName + ": " + op1(prName);
                    PrintAndLog(prtC5);  
                    op2(prName);
                    op3(prName);
                    op4(prName);
                    break;
                case 6:
                    String prtC6 = "Returning to menu...";
                    PrintAndLog(prtC6);
                    endLine();
                    dispMenu();
                    break;
                default:
                    String prtDef = "Enter 1-6";
                    PrintAndLog(prtDef);
            }
            System.out.println("");
        }
    }

    private static int op1(String prn){ // return value is used here because this code can be reused.
        int cn=0;
        for(int i=1;i<province.length;i++){ 
            if(province[i].equals(prn)){
                cn++;
            }
        }
        return cn;
    }

    private static void op2(String prn){
        int aPrj = op1(prn);    // finding total by calling op1;
        float perAll=0, calc=0;
        if(aPrj!=0){
            calc = (float)(aPrj*100)/(lineNum-1);  // no. of projects in province divided by total no in Canada. 
        }
        perAll = (float) Math.round(calc*100)/100;
        String prt = "Percentage of all projects located in " + prn + ": " + perAll + "%";
        PrintAndLog(prt);
    }

    private static void op3(String prn){
        int aPrj=op1(prn), cnOng=0;
        float calc,perOng = 0;
        if(aPrj!=0){
            for(int i=1;i<province.length;i++){
                if(province[i].equals(prn) && stage[i].equals("Ongoing")){
                    cnOng++;
                }
            }
            calc = (float)cnOng*100/aPrj;    //  no. of ongoing projects divided by total number of projects in province.
            perOng = (float) Math.round(calc*100)/100;
        }
        String prt = "Total number of Ongoing Projects: " + cnOng + " & Percentage: " + perOng + "%";
        PrintAndLog(prt);
    }

    private static void op4(String prn){
        int cnCmp=0, aPrj = op1(prn);
        float perCmp=0, calc=0;
        if(aPrj!=0){
            for(int i=1;i<province.length;i++){
                if(province[i].equals(prn) && stage[i].equals("Completed")){
                    cnCmp++;
                }
            }
            calc = (float)cnCmp*100/aPrj;    //  no. of completed projects divided by total number of projects in province.
            perCmp = (float) Math.round(calc*100)/100;
        } 
        String prt = "Total number of Completed Projects: " + cnCmp + " & Percentage: " + perCmp + "%";
        PrintAndLog(prt);
    }

    private static void endLine(){
        String eLine = "-----------------------------------------------------------------------------";
        PrintAndLog(eLine);
        PrintAndLog("");
    }

    private static void PrintAndLog(String txt) // writing output to user in a log file (after menu method is called).
    {
        System.out.println(txt);
        try
        {
            FileOutputStream fileStrm = new FileOutputStream("log.txt", true); 
            PrintWriter pw = new PrintWriter(fileStrm);	 	
            pw.println(txt);
            pw.close();		 
        }
        catch(IOException e)
        {			 
            System.out.println("Error in writing to file: " + e.getMessage());
        }   
    }
    public static void erFile(){    // clearing previous logs of previous session after program start.
        try{
            PrintWriter er = new PrintWriter(new FileOutputStream("log.txt"));
            er.println("");
            er.close();
        }
        catch(IOException e)
        {			 
            System.out.println("Error in clearing previous logs: " + e.getMessage());
        }
    }
}