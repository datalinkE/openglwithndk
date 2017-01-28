package tk.datalinke.openglwithndk;

/**
 * Created by datalink on 28.01.2017.
 */
import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

import android.opengl.GLSurfaceView.Renderer;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class GameSurfaceView extends GLSurfaceView {

    public class GameRenderer implements Renderer {
        @Override
        public void onSurfaceCreated(GL10 gl, EGLConfig config) {
            on_surface_created();
        }

        @Override
        public void onSurfaceChanged(GL10 gl, int width, int height) {
            on_surface_changed(width, height);
        }

        @Override
        public void onDrawFrame(GL10 gl) {
            on_draw_frame();
        }
    }

    private Renderer mRenderer;

    public GameSurfaceView (Context context, AttributeSet attrs) {
        super(context, attrs);
        mRenderer = new GameRenderer();
        setEGLContextClientVersion(2);
        setRenderer(mRenderer);
        setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY); // calls onDrawFrame(...) continuously
    }

    private static native void on_surface_created();
    private static native void on_surface_changed(int width, int height);
    private static native void on_draw_frame();
}
