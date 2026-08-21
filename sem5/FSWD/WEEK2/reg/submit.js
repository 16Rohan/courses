const regform = document.getElementById("regform");

regform.addEventListener("submit", function(event) {
    event.preventDefault();

    const formData = new FormData(regform);

    console.log(formData.get("username"));
});
