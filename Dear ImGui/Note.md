```
ImGuiStyle& style = ImGui::GetStyle(); เป็น global ไม่สามารถเซ็ตแยกในแต่ละ window ได้
ถ้าจะเซ็ตให้แต่ละ window มีสไตล์ที่แตกต่างกันให้ใช้ ImGui::PushStyleVar() และ ImGui::PopStyleVar()
```
ตัวอย่าง
```cpp
	// Global Style
	ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding   = 4.0f;
    style.WindowBorderSize = 4.0f;
    style.WindowPadding    = {0.0f, 0.0f};


void my_window_1() {
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    ImGui::Begin("Window 1");
    ImGui::Text("Hello Window 1");
    ImGui::End();

    ImGui::PopStyleVar(3); // pop all style from ImGui::PushStyleVar
}

void my_window_2() {
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

    ImGui::Begin("Window 2");
    ImGui::Text("Hello Window 2");
    ImGui::End();

    ImGui::PopStyleVar(2); // pop all style from ImGui::PushStyleVar
}
```