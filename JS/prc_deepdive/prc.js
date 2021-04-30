const person = {
    firstname: "Ungmo",
    lastname: "Lee",

    get fullName() {
        return `${this.firstname} ${this.lastname}`
    },
    set fullName(name) {
        [this.firstname, this.lastname] = name.split(' ')
    }
};

console.log(person.firstname + ' ' + person.lastname)
person.fullName = 'Heegun Lee'
console.log(person)

console.log(person.fullName)

let descriptor = Object.getOwnPropertyDescriptor(person, 'firstName')
console.log(descriptor)

descriptor = Object.getOwnPropertyDescriptor(person, "fullName")
console.log(descriptor)