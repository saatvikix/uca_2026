const xhr = new XMLHttpRequest();
xhr.open("GET", "https://dummyjson.com/users");   // used an alternate url as dummyapi is not working
xhr.send();


xhr.onload = () => {

    if (xhr.status === 200) {

        const data = JSON.parse(xhr.responseText);
        const users = data.users;

        const activeStatus = ["Active", "Inactive"];


        /// manually adding an activeStatus field because the data doesn't have one
        users.forEach(user => {

            user.activeStatus = activeStatus[Math.floor(Math.random() * 2)];

        });


        users.forEach(user => {

            console.log( `${user.firstName} - ${user.activeStatus}`);

        });

    }

    else {
        console.log("Request failed :(");
    }

};


xhr.onerror = () => {
    console.log("Error occured :(");
};