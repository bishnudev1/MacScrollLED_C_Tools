# MacScrollLED

> A lightweight macOS CLI utility to control the **Scroll Lock LED** on external keyboards. Perfect for toggling **RGB lights** or triggering **KVM switches** using macOS.

---

## 💡 Why This Exists

Some budget-friendly RGB or KVM combo keyboards (like those from **Zebronics**, **Zebronics Transformer**, etc.) use the **Scroll Lock key** as a signal to toggle lighting or switch inputs.  
While this works out-of-the-box on Windows, **macOS does not offer native support** for toggling the Scroll Lock LED programmatically.

This tool solves that problem by:
- Directly interacting with the **IOKit HID APIs**
- Triggering **ON or OFF** state of the Scroll Lock LED
- Allowing users to use their RGB/KVM functionality **from macOS**

---

## 🖥️ How to Use

1. Clone or download the source files.

2. **Compile the tools:**

```bash
clang -framework IOKit -framework CoreFoundation -o kvm_on scrolllock_on.c
clang -framework IOKit -framework CoreFoundation -o kvm_off scrolllock_off.c


sudo ./kvm_on   # Turns ON Scroll Lock LED (activates RGB/KVM)
sudo ./kvm_off  # Turns OFF Scroll Lock LED

⚠️ sudo is required because controlling HID devices needs elevated permission.


🔧 Advanced Usage
You can wrap these into:
A macOS menu bar utility
A dockless .app
A launch agent or global shortcut
If you'd like to contribute to GUI or automation versions, PRs are welcome!
🧠 Example Hardware Compatibility
Tested and works with:
Zebronics Transformer Combo (Keyboard + Mouse)
Other USB HID-compliant keyboards that use Scroll Lock LED for triggers

MIT License

Copyright (c) 2025 Bishnudev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions...

[MIT license continues]

🙌 Credits
Crafted with ❤️ by @Bishnudev
If this helped, feel free to ⭐️ the repo or contribute!
