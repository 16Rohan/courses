import MyButton from "./components/Button";
import DisplayUser from "./components/User";

function App() {
    return (
        
        <div>
            <title>My React App</title>
            <h3>This is my react app</h3>
            <MyButton />
            <DisplayUser className="ms" user={{name: "Ajay Kumar",
                email: "mail@ajay.com",
                age: 30}} />
        </div>
    );
}

export default App;

