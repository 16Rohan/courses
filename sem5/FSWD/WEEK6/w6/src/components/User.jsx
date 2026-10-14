function DisplayUser({user}) {
    return (
        <div>
            <h3>User Information</h3>
            <p>Name: {user.name}</p>
            <p>Email: {user.email}</p>
            <p>Age: {user.age}</p>
        </div>
    );
}

export default DisplayUser;