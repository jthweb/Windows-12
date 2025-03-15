<div style="text-align: center;">

![Logo](https://raw.githubusercontent.com/jthdev/Windows-12/refs/heads/main/logo.png)

Imagine starting your day with a [fresh cup of coffee](https://ko-fi.com/jthdev) and a brand new Windows experience... 🤔 That's what this is!
<br><br>
A free, open-source concept of Windows 12, made with passion.
<br><br>
[![forthebadge](https://forthebadge.com/images/badges/for-you.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)

</div>

----

Hey everyone! I'm Jonathan, a high school student tinkering with tech. I am the developer of the Windows 12 Concept.

It's free, open-source, and made with ❤️.

If you enjoy what I'm brewing up and want to support my work, you can buy me a coffee at [Ko-fi](https://ko-fi.com/jthdev). Your feedback and contributions are what keep this project going.

---

## ✨ What is Windows 12 Concept?

Windows 12 Concept is a free, open-source project exploring a potential future for Windows. It features a redesigned interface, new features, and a focus on user experience.

It is a concept, not a finished product.

<br>

## ⚡ What's New?

### 1️⃣ Windows Intelligence:
- Integrated with "Writing Tools" by [theJayTea](https://github.com/theJayTea/WritingTools).
- Smarter writing assistance.

### 2️⃣ Quick Bar:
- Quick access to your favorite apps and commands.
- Streamlined workflow.

### 3️⃣ Redesigned Look:
- A clean, modern file explorer with custom icons.
- Minimal wallpapers by [Addy Visuals](https://youtube.com/@addyvisuals)

### 4️⃣ Run App Revamp:
- Search commands, drop files, pick them up later.
- Simple and efficient.

### 5️⃣ Time Widgets:
- Stay on top of your schedule with these widgets.
- Seamless integration using Rainmeter.

### 6️⃣ All New Start Menu:
- Get better productivity with increased ease.
- Also gets new fluent flyouts and a Volume mixer.

### 7️⃣ Winver for Windows 12:
- Latest `winver.exe` with Windows 12 as OS!

### 8️⃣ Dock Taskbar
- Get a hiddden taskbar that only opens on hover!
- Faster app switching
<br>

---

## 📦 **Installation**

1.  Star the repo and grab the latest release from [Releases](https://github.com/jthdev/Windows-12/releases).
2.  Run the installer.
3. Follow all the steps shown in the below tutorial video on how to install Windows 12. (This process will take some time. Please ensure that you have time while installing Windows 12.)
4. Install [Rainmeter]("https://www.rainmeter.com) and [YASB](https://github.com/amnweb/yasb)
<br><video src="tutorial.mp4"></video>
<br>
5. Enjoy your Windows 12 experience! 🚀

> [!TIP]
> 👀 Use HackBGRT to change the boot logo to make the experience even more better!

### 💻 Codes required during installation
```bash
winget install --id=Rainmeter.Rainmeter -e
winget install --id AmN.yasb
```
<br>

## <strike>📦</strike> **Uninstallation**

1.  Please remember that **UNINSTALLING Windows 12 will NOT remove** all the changes made by the app. To restore to the old version, use the below codes and restore the backups made during the installation.

### 💻 Codes required during uninstallation
```bash
winget uninstall --id=Rainmeter.Rainmeter -e
winget uninstall --id AmN.yasb
``` 

You can restore the icons using the `Restore` option from the 7tsp Icon Patcher, uninstall the `UltraUXThemePatcher`, uninstall OldNewExplorer/Explorer Blur Mica, restore the old `winver.exe` and `run.exe`, and replace the current theme with the `.deskthemepack` file that was made earlier during the installation. Also, remove all the shortcuts made from the `shell:startup` folder. Then reboot your computer and then, uninstall Windows 12 from the Start Menu or Control Panel.
<br><br>**OR**<br><br>You can use the code `SFC /scannow` in cmd, to restore the theme and icon much faster. <i>(not recommmended)</i>

>   [!WARNING]
> 🔑 Remember to follow all the steps provided for each step with extreme care to ensure the app is installed or uninstalled correctly. <br><br>Make sure that you don't reboot your computer any time during the installation, even if the apps ask you to.

---

## 🛠️ **Troubleshooting**

-   Use the latest version.
-   Avoid rebooting during installation.
-   For issues, open a GitHub issue.

## 📜 **References**

Special thanks to:

-   Cursor - [JepriCreations](https://deviantart.com/jepricreations)
-   Quick Bar - [YASB by AmN](https://github.com/amnweb)
-   Base theme and Icons - [niivu](https://deviantart.com/niivu)
-   HackBGRT - [Metabolix](https://github.com/Metabolix)
-   Rainmeter - [Rainmeter](https://www.rainmeter.com)
-   Windows Intelligence - [Writing Toold by theJayTea](https://github.com/thejaytea)
-   Start Menu and Flyout - [JaxCore](https://github.com/jaxcore)

And [JThDev](https://github.com/jthdev) for (since you may ask what I made after reading the above references 😅):

- Making the themes
- Creating the Windows 12 `winver.exe` and `Run` <i>(Run drag/drop wasn't easy!)</i>
- Making a completely new taskbar for Windows 12 <i>(not easy)</i>
- Including a custom `YASB` Configuration
- Compiling the whole thing
- Making the Installer

## 📬 Contact

Contact me at [jthdev@duck.com](mailto:jthdev@duck.com)

Made with ❤️ by a high school student. Check out my other projects in Github profile!
## 📄 **License**

GNU General Public License v3.0. See [LICENSE](LICENSE).

## ⚠️ **Disclaimer**

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

<br><br>
```javascript
try {
    if (u_scrolled_till_here) {
        star_repo();
        return "thanks in advance";
    }
} catch {
    if (u_liked_this_project) {
        share_repo(let_others_use);
    }
} finally {
    return "thanks for checking it out! \n  Explore my other projects.";
}