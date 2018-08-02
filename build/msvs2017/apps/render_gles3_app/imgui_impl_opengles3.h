// Pubic interface
IMGUI_IMPL_API bool ImGui_ImplOpenGLES3_Init();
IMGUI_IMPL_API void ImGui_ImplOpenGLES3_Shutdown();
IMGUI_IMPL_API void ImGui_ImplOpenGLES3_RenderDrawData(ImDrawData* draw_data);

// Called by Init/NewFrame/Shutdown
IMGUI_IMPL_API bool ImGui_ImplOpenGLES3_CreateFontsTexture();
IMGUI_IMPL_API void ImGui_ImplOpenGLES3_DestroyFontsTexture();
IMGUI_IMPL_API bool ImGui_ImplOpenGLES3_CreateDeviceObjects();
IMGUI_IMPL_API void ImGui_ImplOpenGLES3_DestroyDeviceObjects();
