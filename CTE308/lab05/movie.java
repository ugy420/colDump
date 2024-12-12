import java.sql.*;
import java.util.Scanner;

class movie{
    static Connection connection;
    static String jdbcUrl, uname, pword;
    static Statement statement;
    static PreparedStatement preparedStatement;
    public static void main(String[] args){    
        try {
            jdbcUrl = "jdbc:mysql://localhost:3306/moviedb";
            uname = "root";
            pword = "";

            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(jdbcUrl, uname, pword);
            statement = connection.createStatement();

            int opt = 5;
            Scanner sc = new Scanner(System.in);
            showOptions();

            enum MenuOption{
                EXIT_PROGRAM,
                DISPLAY_ALL,
                ADD_DATA,
                DELETE_DATA,
                UPDATE_DATA
            }

            while(opt!=MenuOption.EXIT_PROGRAM.ordinal()){     // fancy way of saying opt != 0. ordinal() gets integer 
                                                                // value corresponding to each enum value.
                opt = sc.nextInt();
                MenuOption selectedOption = MenuOption.values()[opt];

                switch(selectedOption){
                    case DISPLAY_ALL:
                        displayAll();
                        System.out.println();
                        break;

                    case ADD_DATA:
                        sc.nextLine(); // Consume the newline character left by sc.nextInt() used in reading option 2.

                        System.out.println("Enter movie title.");
                        String mName = sc.nextLine();

                        System.out.println("Enter Director.");
                        String mDir = sc.nextLine();

                        System.out.println("Enter Release Year.");
                        int mYr = sc.nextInt();

                         sc.nextLine();

                        System.out.println("Enter Genre.");
                        String mGen = sc.nextLine();

                        System.out.println("Enter Price.");
                        String mPri = sc.nextLine();

                        System.out.println("Enter IMDB Rating.");
                        float mImdb = sc.nextFloat();
                        
                        addData(mName, mDir, mYr, mGen, mPri, mImdb);
                        System.out.println();
                        break;

                    case DELETE_DATA:
                        System.out.println("Enter movie id to be deleted.");
                        int delMovie = sc.nextInt();
                        delData(delMovie);
                        System.out.println();
                        break;
                    
                    case UPDATE_DATA:
                        sc.nextLine(); // similar to case 2.

                        System.out.println("Enter movie id to be updated");
                        int movieID = sc.nextInt();

                        sc.nextLine();

                        System.out.println("Enter updated movie title.");
                        String uName = sc.nextLine();

                        System.out.println("Enter updated Director.");
                        String uDir = sc.nextLine();

                        System.out.println("Enter updated Release Year.");
                        int uYr = sc.nextInt();

                        sc.nextLine();

                        System.out.println("Enter updated Genre.");
                        String uGen = sc.nextLine();

                        System.out.println("Enter updated Price.");
                        String uPri = sc.nextLine();

                        System.out.println("Enter updated IMDB Rating.");
                        float uImdb = sc.nextFloat();

                        updateData(movieID, uName, uDir, uYr, uGen, uPri, uImdb);
                        System.out.println();
                        break;

                    case EXIT_PROGRAM:
                        System.out.println("Exited...");
                        break;
                }
            }
            sc.close();
            connection.close();
        }
        catch(ClassNotFoundException e){
            e.printStackTrace();
        }
        catch(SQLException e){
            e.printStackTrace();
        }
    }

    static void showOptions(){
        System.out.println("Enter 0-4");
            System.out.println("1. Retrieve all data");
            System.out.println("2. Add data");
            System.out.println("3. Delete data");
            System.out.println("4. Update data");
            System.out.println("0. Exit program");
    }

    static void displayAll(){
        try{
            String query = "SELECT * FROM movie";

            ResultSet resultSet = statement.executeQuery(query);

            while (resultSet.next()) {
                int id = resultSet.getInt("movieID");
                String name = resultSet.getString("movieName");
                String dir = resultSet.getString("director");
                int rel = resultSet.getInt("releaseYear");
                String pri = resultSet.getString("price");
                float imdb = resultSet.getFloat("IMDB_Rating");
                
                String str = "ID: " + id + " | Title: " + name + " | Director: " + dir + " | Release Year: " + 
                rel + " | Price: " + pri + " | IMDB Rating: " + imdb;

                System.out.println(str);
            }
        }
        catch(SQLException e){
            e.printStackTrace();
        }
    }

    static void addData(String movieName, String dir, int year, String genr, String pri, float imdb){
        try {
            String query = "INSERT INTO movie (movieName, director, releaseYear, genre, price, IMDB_Rating) VALUES (?, ?, ?, ?, ?, ?)";
            
            preparedStatement = connection.prepareStatement(query);
            preparedStatement.setString(1, movieName);
            preparedStatement.setString(2, dir);
            preparedStatement.setInt(3, year);
            preparedStatement.setString(4,genr);
            preparedStatement.setString(5, pri);
            preparedStatement.setFloat(6, imdb);
            
            int rowsInserted = preparedStatement.executeUpdate();
            if(rowsInserted > 0){
                System.out.println("'" + movieName + "' data has been added successfully.");
            }
            else{
                System.out.println("Failed to add the data.");
                System.out.println();
                showOptions();
            }
        }
        catch (SQLException e){
            e.printStackTrace();
        }
    }

    static void delData(int movieID){
        try{
            String query = "DELETE FROM movie WHERE movieID = ?";
            preparedStatement = connection.prepareStatement(query);
            preparedStatement.setInt(1, movieID);
            int rowsDeleted = preparedStatement.executeUpdate();
            if(rowsDeleted > 0){
                System.out.println("Data has been deleted successfully");
            }
            else{
                System.out.println("Failed to delete the data.");
                System.out.println();
                showOptions();
            }
        }
        catch(SQLException e){
            e.printStackTrace();
        }
    }

    static void updateData(int id, String uName, String uDir, int uYear, String uGen, String uPri, float uRat){
        try{
            String query = "UPDATE movie SET movieName = ?, director = ?, releaseYear = ?, genre = ?, price = ?, IMDB_Rating = ? WHERE movieID = ?";
            preparedStatement = connection.prepareStatement(query);
            preparedStatement.setString(1,uName);
            preparedStatement.setString(2, uDir);
            preparedStatement.setInt(3, uYear);
            preparedStatement.setString(4,uGen);
            preparedStatement.setString(5, uPri);
            preparedStatement.setFloat(6, uRat);
            preparedStatement.setInt(7,id);

            int rowsUpdated = preparedStatement.executeUpdate();
            if(rowsUpdated>0){
                System.out.println("Data updated successfully.");
            }
            else{
                System.out.println("Failed to update data.");
                System.out.println();
                showOptions();
            }
        }
        catch(SQLException e){
            e.printStackTrace();
        }
    }
    
}