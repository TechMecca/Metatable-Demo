# **Lua Metatable Demo for WoW 3.3.5a (Lua 5.1)**

This repository contains a demonstration of working with Lua metatables and userdata in the context of Lua 5.1, specifically tailored for integration with World of Warcraft 3.3.5a's Lua environment.

---

## **Overview**

This project demonstrates:
- Creating and registering a custom metatable (`MyStructMeta`).
- Defining userdata (`MyStruct`) and associating it with the metatable.
- Registering C++ functions (`GetValue`, `SetValue`) as methods of the metatable.
- Exposing a global Lua function (`CreateMyStruct`) for creating instances of the userdata.

The code is designed to interact seamlessly with Lua scripts, making it suitable for extensions, addons, or custom scripting in World of Warcraft 3.3.5a.

---

## **Features**
1. **Custom Metatable**:
   - `MyStructMeta` defines behavior for `MyStruct` userdata objects.
   - Includes methods `GetValue` and `SetValue` for interacting with the `MyStruct` object.

2. **Userdata**:
   - Demonstrates creation and manipulation of userdata in Lua via C++.

3. **Global Function**:
   - `CreateMyStruct`: A Lua-accessible function that creates a new `MyStruct` object.

4. **Lua 5.1 Compatibility**:
   - Fully compatible with the Lua version used in WoW 3.3.5a.

---

## **Requirements**

### **Dependencies**
- **Lua 5.1**:
  - Ensure you have Lua 5.1 installed or available in your development environment.
- **World of Warcraft 3.3.5a**:
  - This project is specifically designed for the Lua environment embedded in WoW 3.3.5a.

### **Compiler**
- A C++ compiler supporting the Windows environment (e.g., MSVC).

---

## **How It Works**

1. **Metatable Setup**:
   - The `MetaDemo` function creates a metatable (`MyStructMeta`) and registers methods (`GetValue`, `SetValue`).

2. **Userdata Initialization**:
   - The `CreateMyStruct` function creates a new `MyStruct` userdata object and associates it with the `MyStructMeta` metatable.

3. **Lua Integration**:
   - Lua scripts can create and interact with `MyStruct` objects using the registered methods.

---

## **Code Structure**

### **Main Functions**
- **`CreateMyStruct`**:
  - Creates a `MyStruct` userdata object and initializes its `value` field.
  - Usage in Lua:
    ```lua
    local obj = CreateMyStruct(42) -- Creates a new MyStruct with value 42
    ```

- **`MyStruct_GetValue`**:
  - Retrieves the `value` field from a `MyStruct` object.
  - Usage in Lua:
    ```lua
    print(obj:GetValue()) -- Outputs the value of the MyStruct object
    ```

- **`MyStruct_SetValue`**:
  - Updates the `value` field of a `MyStruct` object.
  - Usage in Lua:
    ```lua
    obj:SetValue(100) -- Updates the value to 100
    ```

- **`MetaDemo`**:
  - Registers the metatable and global functions during initialization.

### **Methods Table**
- `MyStructMethods`:
  - Contains the methods `GetValue` and `SetValue` mapped to their respective C++ functions.

---

## **Example Lua Script**

```lua
-- Load the library
require("metatable_demo")

-- Create an instance of MyStruct
local obj = CreateMyStruct(42)

-- Access and modify its value
print("Initial Value:", obj:GetValue()) -- Outputs: Initial Value: 42
obj:SetValue(100)
print("Updated Value:", obj:GetValue()) -- Outputs: Updated Value: 100
```

---

## **Notes**
- This example does not include a `__gc` metamethod as `MyStruct` does not manage dynamically allocated memory or external resources.
- Ensure the module is compiled and loaded correctly in your WoW 3.3.5a environment.

---

## **Contributing**
Feel free to fork the repository and submit pull requests for improvements or new features.

---

## **License**
This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## **Acknowledgments**
Special thanks to the World of Warcraft modding community and Lua enthusiasts for providing inspiration and support for this project.
